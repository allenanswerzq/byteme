/* created   : 2020-12-08 23:17:16
 * accepted  : 2020-12-08 23:31:34
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
  int ans = 0;
  vector<int> d(N);
  std::function<void(int, int)> dfs = [&](int u, int p) {
    for (int& v : g[u]) {
      if (v == p) continue;
      dfs(v, u);
      ans = max(ans, d[u] + d[v] + 1);
      d[u] = max(d[u], d[v] + 1);
    }
  };
  dfs(0, -1);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
