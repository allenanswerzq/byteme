/* created   : 2020-11-29 21:57:31
 * accepted  : 2020-12-05 23:49:12
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

struct Segtree {
  struct node {
    ll sum = 0;
    ll z0 = 0;
    ll z1 = 0;

    void apply(int l, int r, ll x0, ll x1, int d) {
      r--;
      // [a ... ...           b]
      //       [l2 ... r2]
      // l2 - a + 1, l2 - a + 2, ... l2 - a + r2 - l2 + 1
      // ==> (1 - a) * (r2 - l2 + 1) + (l2 + l2 + 1, ..., r2)
      sum += d + (ll) (r - l + 1) * x0 + x1 * ((ll) r * (r + 1) / 2 - (ll) l * (l - 1) / 2);
      z0 += x0;
      z1 += x1;
    }
  };

  node unite(const node& a, const node& b) const {
    return node{a.sum + b.sum, 0, 0};
  }

  inline void push_down(int x, int l, int r) {
    int md = l + (r - l) / 2;
    tree[x << 1].apply(l, md, tree[x].z0, tree[x].z1, 0);
    tree[x << 1 | 1].apply(md, r, tree[x].z0, tree[x].z1, 0);
    tree[x].z0 = 0;
    tree[x].z1 = 0;
  }

  inline void pull_up(int x) {
    tree[x] = unite(tree[x << 1], tree[x << 1 | 1]);
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
    pull_up(x);
  }

  template <typename U>
  void build(int x, int l, int r, const vector<U>& v) {
    if (l + 1 == r) {
      assert(0 <= l && l < (int) v.size());
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = l + (r - l) / 2;
    build(x << 1, l, y, v);
    build(x << 1 | 1, y, r, v);
    pull_up(x);
  }

  node queryImpl(int x, int l, int r, int lx, int rx) {
    if (rx <= l || r <= lx) {
      return node{};
    }
    if (lx <= l && r <= rx) {
      return tree[x];
    }
    push_down(x, l, r);
    int y = l + (r - l) / 2;
    node left = queryImpl(x << 1, l, y, lx, rx);
    node right = queryImpl(x << 1 | 1, y, r, lx, rx);
    node res = unite(left, right);
    pull_up(x);
    return res;
  }

  void debugImpl(int x, int l, int r, int lx, int rx, int level = 1) {
    if (rx <= l || r <= lx) {
      return;
    }
    if (l + 1 < r) {
      push_down(x, l, r);
    }
    if (lx <= l && r <= rx) {
      // trace(l, r, tree[x].sum, tree[x].z0, tree[x].z1);
      cerr << string(level, ' ') << l << "->" << r << " "
           << tree[x].sum << " " << tree[x].z0 << " " << tree[x].z1 << "\n";
    }
    if (l + 1 < r) {
      int y = l + (r - l) / 2;
      debugImpl(x << 1, l, y, lx, rx, 2 * level);
      debugImpl(x << 1 | 1, y, r, lx, rx, 2 * level);
      pull_up(x);
    }
  }

  template <typename ...U>
  void modifyImpl(int x, int l, int r, int lx, int rx, const U&... v) {
    if (rx <= l || r <= lx) {
      return;
    }
    if (lx <= l && r <= rx) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = l + (r - l) / 2;
    push_down(x, l, r);
    if (lx < y) {
      modifyImpl(x << 1, l, y, lx, rx, v...);
    }
    if (rx > y) {
      modifyImpl(x << 1 | 1, y, r, lx, rx, v...);
    }
    pull_up(x);
  }

  int ceil_pow2(int x) {
    int t = 1;
    while (t < x) {
      t <<= 1;
    }
    return t;
  }

  Segtree(int n_) : n(ceil_pow2(n_)) {
    tree.resize(2 * n);
    build(1, 0, n);
  }

  template <typename M>
  Segtree(vector<M>& v) : n(ceil_pow2(v.size())) {
    tree.resize(2 * n);
    v.resize(n);
    build(1, 0, n, v);
  }

  node query(int lx, int rx) {
    assert(0 <= lx && lx <= rx && rx <= n);
    return queryImpl(1, 0, n, lx, rx);
  }

  template <typename ...M>
  void modify(int lx, int rx, const M&... v) {
    assert(0 <= lx && lx <= rx && rx <= n);
    modifyImpl(1, 0, n, lx, rx, v...);
  }

  void debug() {
    debugImpl(1, 0, n, 0, n);
  }
};

void solve() {
  int N, Q; cin >> N >> Q;
  Segtree seg(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    seg.modify(i, i + 1, 0, 0, x);
  }
  // seg.debug();
  for (int i = 0; i < Q; i++) {
    int op, a, b; cin >> op >> a >> b;
    a--, b--;
    if (op == 1) {
      seg.modify(a, b + 1, 1 - a, 1, 0);
      // seg.debug();
    }
    else {
      cout << seg.query(a, b + 1).sum << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
