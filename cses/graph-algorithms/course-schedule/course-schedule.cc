/* created   : 2020-11-19 15:38:36
 * accepted  : 2020-11-19 16:34:49
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[v].push_back(u);
  }
  vector<int> ans;
  vector<int> vis(N);
  std::function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int v : g[u]) {
      if (vis[v] == 1) {
        // Cycle exists.
        cout << "IMPOSSIBLE\n";
        exit(0);
      }
      else if (vis[v] == 0) {
        dfs(v);
      }
      else {
        // Already been processsed.
      }
    }
    ans.push_back(u);
    vis[u] = 2;
  };
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  trace(ans);
  assert(ans.size() == N);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << (i == ans.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
