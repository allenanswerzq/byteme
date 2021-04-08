/* created   : 2021-04-08 22:16:09
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
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
    // Do dfs
    dfs(0);
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
    pos[v] = cnt++;
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

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
