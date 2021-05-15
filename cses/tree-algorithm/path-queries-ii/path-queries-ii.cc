/* created   : 2021-04-08 22:16:09
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

struct Tree {
  vector<vector<int>> g;
  vector<vector<int>> f;
  vector<int> enter;
  vector<int> leave;
  vector<int> depth;
  vector<int> parent;
  // heavy light decomposition
  vector<int> heavy;
  vector<int> head;
  vector<int> pos;
  int cnt;
  int n;
  int h;

  Tree(int n_) : n(n_) {
    cnt = 0;
    g.resize(n);
    parent.resize(n, -1);
    enter.resize(n);
    leave.resize(n);
    depth.resize(n);
    heavy.resize(n, -1);
    head.resize(n);
    pos.resize(n);
  }

  void add_edge(int u, int v) {
    g[u].push_back(v);
  }

  int dfs(int u) {
    enter[u] = cnt++;
    int tot_size = 1;
    int largest_subsize = 0;
    for (int v : g[u]) {
      if (v == parent[u]) continue;
      parent[v] = u;
      depth[v] = depth[u] + 1;
      int cur_size = dfs(v);
      tot_size += cur_size;
      if (cur_size > largest_subsize) {
        // Compute the heavy edge for node u
        largest_subsize = cur_size;
        heavy[u] = v;
      }
    }
    leave[u] = cnt;
    return tot_size;
  }

  void decompose(int u, int h) {
    head[u] = h;
    pos[u] = cnt++;
    if (heavy[u] != -1) {
      decompose(heavy[u], h);
    }
    for (int v : g[u]) {
      if (v == parent[u] || v == heavy[u]) continue;
      decompose(v, v);
    }
  }

  // Build heavy light decomposition
  void build_hld() {
    cnt = 0;
    decompose(0, 0);
  }

  int ceil_pow2(int x) {
    int t = 0;
    while ((1ll << t) <= x) {
      t++;
    }
    return t;
  }

  void build_lca() {
    int max_depth = *max_element(depth.begin(), depth.end());
    h = ceil_pow2(max_depth);
    f.resize(n, vector<int>(h, -1));
    for (int i = 0; i < n; i++) {
      f[i][0] = parent[i];
    }
    for (int i = 1; i < h; i++) {
      for (int u = 0; u < n; u++) {
        int p = f[u][i - 1];
        f[u][i] = (p < 0 ? -1 : f[p][i - 1]);
      }
    }
  }

  bool isancestor(int u, int v) {
    return (enter[u] <= enter[v] && leave[v] <= leave[u]);
  }

  // Binary lifting
  int lca(int u, int v) {
    assert(0 <= u && u < n);
    assert(0 <= v && v < n);
    if (isancestor(u, v)) {
      return u;
    }
    else if (isancestor(v, u)) {
      return v;
    }
    else {
      for (int i = h - 1; i >= 0; i--) {
        if (f[u][i] > 0 && !isancestor(f[u][i], v)) {
          u = f[u][i];
        }
      }
      return f[u][0];
    }
  }
};

struct Segtree {
  struct node {
    int mx = 0;

    void apply(int l, int r, int val) { mx = val; }

    string debug_string() { return to_string(mx); }
  };

  node unite(const node& a, const node& b) const {
    return node{max(a.mx, b.mx)};
  }

  inline void push_down(int x, int l, int r) {
    (void)x;
    (void)l;
    (void)r;
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

int hld_query(Tree& tree, Segtree& seg, int a, int b) {
  auto& pos = tree.pos;
  auto& head = tree.head;
  auto& depth = tree.depth;
  auto& parent = tree.parent;
  int res = 0;
  for (; head[a] != head[b]; b = parent[head[b]]) {
    if (depth[head[a]] > depth[head[b]]) {
      swap(a, b);
    }
    res = max(res, seg.query(pos[head[b]], pos[b] + 1).mx);
  }
  if (depth[a] > depth[b]) {
    swap(a, b);
  }
  res = max(res, seg.query(pos[a], pos[b] + 1).mx);
  return res;
}

// TODO(TLE):
void solve() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  Tree t(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    t.add_edge(u, v);
    t.add_edge(v, u);
  }
  t.dfs(0);
  t.build_lca();
  t.build_hld();
  Segtree seg(t.cnt);
  for (int i = 0; i < N; i++) {
    seg.modify(t.pos[i], t.pos[i] + 1, A[i]);
  }
  vector<int> ans;
  for (int i = 0; i < Q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int s, x; cin >> s >> x;
      s--;
      seg.modify(t.pos[s], t.pos[s] + 1, x);
    }
    else {
      int a, b; cin >> a >> b;
      a--, b--;
      int c = t.lca(a, b);
      int r = max(hld_query(t, seg, a, c), hld_query(t, seg, b, c));
      ans.push_back(r);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
