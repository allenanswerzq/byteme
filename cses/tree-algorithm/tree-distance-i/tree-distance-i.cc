/* created   : 2020-12-10 22:00:14
 * accepted  : 2020-12-10 22:12:53
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> vis(N);
  std::function<void(int, vector<int>&d)> dfs;
  dfs = [&](int u, vector<int>& d) {
    vis[u] = 1;
    for (int v : g[u]) {
      if (!vis[v]) {
        d[v] = d[u] + 1;
        dfs(v, d);
      }
    }
  };
  vector<int> d(N);
  dfs(0, d);
  int x = max_element(all(d)) - d.begin();
  vector<int> dx(N);
  vis.assign(N, 0);
  dfs(x, dx);
  int y = max_element(all(dx)) - dx.begin();
  vector<int> dy(N);
  vis.assign(N, 0);
  dfs(y, dy);
  for (int i = 0; i < N; i++) {
    cout << max(dx[i], dy[i]) << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
