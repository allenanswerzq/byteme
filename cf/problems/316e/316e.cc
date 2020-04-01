/* created   : 2020-03-31 21:44:32
 * accepted  : 2020-04-01 18:15:55
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int mod = 1e9;
const int N = 2e5 + 7;

ll f[N];
ll ps[N];

ll get_ps(int l, int r) {
  return ps[r + 1] - ps[l];
}

ll func(ll s0, ll s1, ll x) {
  assert(x >= 2);
  return (f[x - 1] * s1 + f[x - 2] * s0) % mod;
}

// Zero-indexed segment tree
class Segtree {
 public:
  struct node {
    ll s0 = 0, s1 = 0, add = 0, len = 0;

    // Each node denotes an interval [l, r).
    void apply(int x, int l, int r, int v) {
      len = r - l;
      s0 = (s0 + get_ps(0, r - l - 1) * v) % mod;
      s1 = (s1 + get_ps(1, r - l) * v) % mod;
      add = (add + v) % mod;
    }

    void assign(int l, int r, int v) {
      if (l + 1 == r) {
        len = 1;
        s0 = v;
        s1 = v;
        add = 0;
      }
    }

    string debug_string() {
      string ret;
      ret += "(";
      ret += to_string(s0);
      ret += ",";
      ret += to_string(s1);
      ret += ",";
      ret += to_string(add);
      ret += ")";
      return ret;
    }

    friend ostream& operator<<(ostream& os, node& a) {
      return os << a.debug_string();
    }
  };

  node combine(const node& a, const node& b) {
    if (a.len == 0) {
      return b;
    }
    node res;
    res.len = a.len + b.len;
    if (a.len == 1) {
      res.s0 = (a.s0 + b.s1 % mod) % mod;
    }
    else {
      res.s0 = (a.s0 + func(b.s0, b.s1, a.len) % mod) % mod;
    }
    res.s1 = (a.s1 + func(b.s0, b.s1, a.len + 1) % mod) % mod;
    return res;
  }

  void push(int x, int l, int r) {
    int y = l + (r - l) / 2;
    if (tree[x].add != 0) {
      tree[x << 1].apply(x << 1, l, y, tree[x].add);
      tree[x << 1 | 1].apply(x << 1 | 1, y, r, tree[x].add);
      tree[x].add = 0;
    }
  }

  void pull(int x) {
    tree[x] = combine(tree[x << 1], tree[x << 1 | 1]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l + 1 == r) {
      return;
    }
    int y = l + (r - l) / 2;
    build(x << 1, l, y);
    build(x << 1 | 1, y, r);
    pull(x);
  }

  string debug_string(int x) {
    return to_string(x) + tree[x].debug_string();
  }

  void walk_tree(Graphviz& gv, int x, int l, int r) {
    trace(x, tree[x]);
    if (x >= n) return;
    gv.add_edge(debug_string(x), debug_string(x << 1));
    gv.add_edge(debug_string(x), debug_string(x << 1 | 1));
    int y = l + (r - l) / 2;
    walk_tree(gv, x << 1, l, y);
    walk_tree(gv, x << 1 | 1, y, r);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M>& v) {
    if (l + 1 == r) {
      assert(0 <= l && l < (int)v.size());
      tree[x].apply(x, l, r, v[l]);
      return;
    }
    int y = l + (r - l) / 2;
    build(x << 1, l, y, v);
    build(x << 1 | 1, y, r, v);
    pull(x);
  }

  node get(int x, int l, int r, int lx, int rx) {
    if (rx <= l || r <= lx) {
      return node{};
    }
    if (lx <= l && r <= rx) {
      return tree[x];
    }
    push(x, l, r);
    int y = l + (r - l) / 2;
    node a = get(x << 1, l, y, lx, rx);
    node b = get(x << 1 | 1, y, r, lx, rx);
    node res = combine(a, b);
    pull(x);
    return res;
  }

  template <typename M>
  void modify(int x, int l, int r, int lx, int rx, const M& v) {
    if (rx <= l || r <= lx) {
      return;
    }
    if (lx <= l && r <= rx) {
      tree[x].apply(x, l, r, v);
      return;
    }
    int y = l + (r - l) / 2;
    push(x, l, r);
    if (lx < y) {
      modify(x << 1, l, y, lx, rx, v);
    }
    if (rx > y) {
      modify(x << 1 | 1, y, r, lx, rx, v);
    }
    pull(x);
  }

  int get_size(int x) {
    int t = 1;
    while (t < x) {
      t <<= 1;
    }
    return t;
  }

  Segtree(int n_) : n(n_) {
    n = get_size(n);
    tree.resize(2 * n);
    build(1, 0, n);
  }

  template <typename M>
  Segtree(const vector<M>& v) {
    n = get_size((int)v.size());
    tree.resize(2 * n);
    vector<M> t = v;
    t.resize(n);
    build(1, 0, n, t);
  }

  node get(int lx, int rx) {
    assert(0 <= lx && lx <= rx && rx <= n);
    return get(1, 0, n, lx, rx);
  }

  node get(int p) {
    assert(0 <= p && p <= n);
    return get(1, 0, n, p, p + 1);
  }

  template <typename M>
  void modify(int lx, int rx, const M& v) {
    assert(0 <= lx && lx <= rx && rx <= n);
    modify(1, 0, n, lx, rx, v);
  }

  template <typename M>
  void set(int lx, int rx, const M& v) {
    assert(0 <= lx && lx <= rx && rx <= n);
    set(1, 0, n, lx, rx, v);
  }

  template <typename M>
  void set(int x, int l, int r, int lx, int rx, const M& v) {
    if (rx <= l || r <= lx) {
      return;
    }
    if (l + 1 == r) {
      tree[x].assign(l, r, v);
      return;
    }
    int y = l + (r - l) / 2;
    push(x, l, r);
    if (lx < y) {
      set(x << 1, l, y, lx, rx, v);
    }
    if (rx > y) {
      set(x << 1 | 1, y, r, lx, rx, v);
    }
    pull(x);
  }
};

void solve() {
  int n, m; cin >> n >> m;
  f[0] = 1, f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % mod;
  }
  for (int i = 0; i <= n; i++) {
    ps[i + 1] = (ps[i] + f[i]) % mod;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Segtree seg(a);
  for (int i = 0; i < m; i++) {
    int op; cin >> op;
    if (op == 1) {
      int x, v; cin >> x >> v;
      x--;
      seg.set(x, x + 1, v);
    }
    else if (op == 2) {
      int l, r; cin >> l >> r;
      auto node = seg.get(--l, r);
      cout << node.s0 << '\n';
    }
    else {
      int l, r, v; cin >> l >> r >> v;
      l--;
      trace(l, r, v);
      seg.modify(l, r, v);
    }
  }
  Graphviz gv("g");
  seg.walk_tree(gv, 1, 0, n);
  gv.draw_graph();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
