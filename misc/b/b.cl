/* created   : 2021-09-11 19:40:39
 * accepted  : 2021-09-11 20:47:15
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(N);
  vector<int> cost(N);
  string ss;
  getline(cin, ss);
  vector<int> deg(N);
  for (int i = 0; i < N; i++) {
    getline(cin, ss);
    istringstream iss(ss);
    string opname;
    iss >> opname >> cost[i];
    int v;
    // i --> v
    while (iss >> v) {
      g[i].push_back(v);
      // g[v].push_back(i);
      deg[v]++;
    }
  }
  assert(deg[0] == 0);
  vector<int> f(N);
  vector<int> visit(N);
  std::function<void(int)> dfs = [&](int u) {
    visit[u] = 1;
    int val = 0;
    for (int v : g[u]) {
      if (visit[v]) continue;
      dfs(v);
      val = max(val, f[v]);
    }
    f[u] = val + cost[u];
  };
  dfs(0);
  cout << f[0] << "\n";
  // int ans = 0;
  // for (int i = 0; i < N; i++) {
  //   if (deg[i] == 0) {
  //     dfs(i);
  //     ans = max(ans, f[i]);
  //   }
  // }
  // cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
