/* created   : 2021-05-26 09:00:15
 * accepted  : 2021-05-27 09:32:29
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

struct Segtree {
  struct node {
    ll gd = 0;

    void apply(int l, int r, ll val) {
      assert(r - l == 1);
      gd = val;
    }

    string debug_string() {
      ostringstream oss;
      oss << gd;
      return oss.str();
    }
  };

  node unite(const node& a, const node& b) const {
    return node{__gcd(a.gd, b.gd)};
  }

  inline void push_down(int x, int l, int r) {
    // int y = l + (r - l) / 2;
    // tree[x << 1].apply(l, y, tree[x].lazy);
    // tree[x << 1 | 1].apply(y, r, tree[x].lazy);
    // tree[x].lazy = 0;
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

  node query_impl(int x, int l, int r, int lx, int rx) {
    if (rx <= l || r <= lx) {
      //          l-------r
      // lx----rx           lx-----rx
      // NOTE: here returns the default value for a node
      return node{};
    }
    if (lx <= l && r <= rx) {
      return tree[x];
    }
    push_down(x, l, r);
    int y = l + (r - l) / 2;
    node left = query_impl(x << 1, l, y, lx, rx);
    node right = query_impl(x << 1 | 1, y, r, lx, rx);
    node res = unite(left, right);
    pull_up(x);
    return res;
  }

  void debug_impl(int x, int l, int r, int lx, int rx, int level = 1) {
    if (rx <= l || r <= lx) {
      return;
    }
    if (l + 1 < r) {
      push_down(x, l, r);
    }
    if (lx <= l && r <= rx) {
      cerr << string(level, ' ')
           << l << "->" << r << " ("
           << tree[x].debug_string()
           << ")\n";
    }
    if (l + 1 < r) {
      int y = l + (r - l) / 2;
      debug_impl(x << 1, l, y, lx, rx, 2 * level);
      debug_impl(x << 1 | 1, y, r, lx, rx, 2 * level);
      pull_up(x);
    }
  }

  template <typename ...U>
  void modify_impl(int x, int l, int r, int lx, int rx, const U&... v) {
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
      modify_impl(x << 1, l, y, lx, rx, v...);
    }
    if (rx > y) {
      modify_impl(x << 1 | 1, y, r, lx, rx, v...);
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

  Segtree() = default;

  Segtree(int n_) { resize(n_); }

  template <typename M>
  Segtree(vector<M>& v) : n(ceil_pow2(v.size())) {
    v.resize(n);
    tree.resize(2 * n);
    build(1, 0, n, v);
  }

  void clear() { tree.clear(); }

  void resize(int n_) {
    n = ceil_pow2(n_);
    tree.resize(2 * n);
    build(1, 0, n);
  }

  node query(int lx, int rx) {
    assert(0 <= lx && lx <= rx && rx <= n);
    return query_impl(1, 0, n, lx, rx);
  }

  template <typename ...M>
  void modify(int lx, int rx, const M&... v) {
    assert(0 <= lx && lx <= rx && rx <= n);
    modify_impl(1, 0, n, lx, rx, v...);
  }

  void debug() {
#ifdef LOCAL
    debug_impl(1, 0, n, 0, n);
#endif
  }
};

const int L = 2e5 + 7;
int N, Q;
vector<vector<int>> g;
vector<vector<ar>> queries;
vector<ll> ans;
map<ar, ar> mp;
Segtree seg;

void dfs(int u, int p = -1) {
  if (p != -1) {
    auto t = mp[{u, p}];
    seg.modify(t[0], t[0] + 1, t[1]);
  }
  for (auto query : queries[u]) {
    int idx = query[0];
    int weight = query[1];
    // Need to pay toll for roads that the current weight exceeds its limit
    ans[idx] = seg.query(0, weight + 1).gd;
    // trace(u, idx, weight, ans[idx]);
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  if (p != -1) {
    auto t = mp[{u, p}];
    seg.modify(t[0], t[0] + 1, 0);
  }
}

void solve() {
  cin >> N >> Q;
  // NOTE: clear everying for each test case.
  mp.clear();
  g.clear();
  queries.clear();
  seg.clear();
  g.resize(N);
  for (int i = 0; i < N - 1; i++) {
    ll u, v, l, a; cin >> u >> v >> l >> a;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    mp[{u, v}] = {l, a};
    mp[{v, u}] = {l, a};
  }
  queries.resize(N);
  for (int i = 0; i < Q; i++) {
    int c, w; cin >> c >> w;
    c--;
    queries[c].push_back({i, w});
  }
  seg.resize(L);
  ans.resize(Q);
  dfs(0);
  for (int i = 0; i < Q; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
