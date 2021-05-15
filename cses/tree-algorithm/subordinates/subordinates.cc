/* created   : 2020-12-07 23:26:59
 * accepted  : 2020-12-07 23:40:37
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(N);
  vector<int> deg(N);
  for (int i = 1; i < N; i++) {
    int x; cin >> x;
    x--;
    g[x].push_back(i);
    deg[i]++;
  }
  vector<int> f(N);
  vector<int> vis(N);
  std::function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int v : g[u]) {
      if (!vis[v]) {
        dfs(v);
      }
      f[u] += f[v] + 1;
    }
  };
  trace(deg);
  for (int i = 0; i < N; i++) {
    if (deg[i] == 0) {
      dfs(i);
      for (int j = 0; j < N; j++) {
        cout << f[j] << (j == N - 1 ? '\n' : ' ');
      }
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
