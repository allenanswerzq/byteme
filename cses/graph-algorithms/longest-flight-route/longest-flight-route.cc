/* created   : 2020-11-19 16:42:43
 * accepted  : 2020-11-19 17:26:31
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
  }
  vector<int> nxt(N);
  const int INF = 1e9;
  vector<int> f(N, -INF);
  f[N - 1] = 1;
  nxt[N - 1] = -1;
  std::function<void(int)> dfs = [&](int u) {
    for (int v : g[u]) {
      if (f[v] == -INF) {
        dfs(v);
      }
      if (f[v] != -INF && f[u] < f[v] + 1) {
        f[u] = f[v] + 1;
        nxt[u] = v;
      }
    }
  };
  dfs(0);
  trace(f[0]);
  if (f[0] == -INF) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  vector<int> ans;
  for (int u = 0; u != -1; u = nxt[u]) {
    ans.push_back(u);
  }
  cout << f[0] << "\n";
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
