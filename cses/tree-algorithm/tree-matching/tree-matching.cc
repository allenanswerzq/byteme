/* created   : 2020-12-08 22:24:52
 * accepted  : 2020-12-08 23:10:35
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
  vector<int> select(N), not_select(N);
  std::function<void(int, int)> dfs = [&](int u, int p) {
    for (int& v : g[u]) {
      if (v == p) continue;
      dfs(v, u);
      select[u] = max({select[u] + max(select[v], not_select[v]),
                       not_select[u] + not_select[v] + 1/*u-->v*/});
      not_select[u] += max(select[v], not_select[v]);
    }
  };
  dfs(0, -1);
  cout << max(select[0], not_select[0]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
