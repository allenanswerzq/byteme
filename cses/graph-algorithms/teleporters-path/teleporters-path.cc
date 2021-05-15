/* created   : 2020-11-24 10:01:01
 * accepted  : 2020-11-24 12:36:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<int> eu(M);
  vector<int> ev(M);
  vector<int> ind(N);
  vector<vector<int>> g(N);
  Graphviz gv(GraphDrawType::Directed);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    gv.gvAddEdge(u, v);
    eu[i] = u;
    ev[i] = v;
    g[u].push_back(i);
    ind[v]++;
  }
  gv.gvDrawGraph();
  for (int i = 0; i < N; i++) {
    int out_deg = g[i].size();
    if (i == 0 && ind[i] + 1 != out_deg) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    else if (i == N - 1 && ind[i] != out_deg + 1) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    else if (i != 0 && i != N - 1 && ind[i] != out_deg) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  vector<int> vis(M);
  vector<int> ans;
  trace(eu, ev, g);
  std::function<void(int)> dfs = [&](int u) {
    while (g[u].size()) {
      int e = g[u].back();
      g[u].pop_back();
      if (vis[e]) continue;
      trace(u, eu[e], ev[e], g[u], ans);
      vis[e] = 1;
      dfs(eu[e] ^ u ^ ev[e]);
      ans.push_back(u);
    }
  };
  dfs(0);
  reverse(all(ans));
  trace(ans);
  if (ans.size() == M) {
    ans.push_back(N - 1);
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] + 1 << (i == ans.size() - 1 ? '\n' : ' ');
    }
  }
  else {
    cout << "IMPOSSIBLE\n";
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
