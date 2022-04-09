/* created   : 2020-11-19 10:52:37
 * accepted  : 2020-11-19 16:29:20
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }
  vector<int> vis(N);
  vector<int> pre(N);
  std::function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int v : g[u]) {
      if (vis[v] == 1) {
        pre[v] = u;  // Connect the cycle up
        vector<int> ans;
        for (int j = v; ;j = pre[j]) {
          ans.push_back(j);
          if (j == v && ans.size() > 1) {
            break;
          }
        }
        reverse(all(ans));
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
          cout << ans[i] + 1 << (i == ans.size() - 1 ? '\n' : ' ');
        }
        exit(0);
      }
      else if (vis[v] == 0) {
        pre[v] = u;
        dfs(v);
      }
      else {
        // NOTE: only happens on directed graph
        // No cycle exists after finished visit node v before
      }
    }
    vis[u] = 2;
  };
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  cout << "IMPOSSIBLE\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
