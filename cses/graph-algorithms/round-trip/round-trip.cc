/* created   : 2020-11-15 09:54:29
 * accepted  : 2020-11-19 12:37:57
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
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> vis(N);
  vector<int> pre(N);
  std::function<void(int, int)> dfs = [&](int u, int p) {
    vis[u] = 1;
    for (int v : g[u]) {
      if (v == p) continue;
      if (vis[v]) {
        pre[v] = u;
        vector<int> ans;
        for (int j = u;;j = pre[j]) {
          ans.push_back(j);
          if (j == u && ans.size() > 1) {
            break;
          }
        }
        cout << ans.size() << "\n";
        reverse(all(ans));
        for (int i = 0; i < ans.size(); i++) {
          cout << ans[i] + 1 << (i == ans.size() - 1 ? '\n' : ' ');
        }
        exit(0);
      }
      else {
        pre[v] = u;
        dfs(v, u);
      }
    }
  };
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      pre[i] = -1;
      dfs(i, -1);
    }
  }
  cout << "IMPOSSIBLE\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
