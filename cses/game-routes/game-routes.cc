/* created   : 2020-11-19 17:16:02
 * accepted  : 2020-11-19 17:54:20
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }
  vector<int> f(N);
  vector<int> vis(N);
  f[N - 1] = 1;
  std::function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int v : g[u]) {
      if (!vis[v]) {
        dfs(v);
      }
      add(f[u], f[v]);
    }
  };
  dfs(0);
  cout << f[0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
