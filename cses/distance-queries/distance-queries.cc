/* created   : 2020-12-13 17:28:39
 * accepted  : 2020-12-13 17:43:37
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, Q; cin >> N >> Q;
  vector<vector<int>> g(N);
  Graphviz gv;
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    gv.gvAddEdge(u, v);
  }
  gv.gvDrawGraph();
  vector<int> enter(N);
  vector<int> leave(N);
  vector<int> depth(N);
  vector<int> pre(N);
  int cnt = 0;
  std::function<void(int, int)> dfs = [&](int u, int p) {
    enter[u] = ++cnt;
    for (int v : g[u]) {
      if (v != p) {
        pre[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
      }
    }
    leave[u] = cnt;
  };
  dfs(0, -1);
  const int K = 20;
  vector<vector<int>> f(N, vector<int>(K));
  for (int i = 0; i < N; i++) {
    f[i][0] = pre[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 0; i < N; i++) {
      int p = f[i][k - 1];
      f[i][k] = (p < 0 ? p : f[p][k - 1]);
    }
  }
  auto is_ancestor = [&](int u, int v) -> bool {
    assert(0 <= u && u < N);
    assert(0 <= v && v < N);
    return (enter[u] <= enter[v] && leave[v] <= leave[u]);
  };
  for (int i = 0; i < Q; i++) {
    int u, v; cin >> u >> v;
    trace(i, u, v);
    u--, v--;
    int c = -1;
    if (is_ancestor(u, v)) {
      c = u;
    }
    else if (is_ancestor(v, u)) {
      c = v;
    }
    else {
      int t = u;
      for (int j = K - 1; j >= 0; j--) {
        if (f[t][j] != -1 && !is_ancestor(f[t][j], v)) {
          t = f[t][j];
        }
      }
      c = f[t][0];
    }
    trace(i, u, v, c);
    cout << depth[u] + depth[v] - 2 * depth[c] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
