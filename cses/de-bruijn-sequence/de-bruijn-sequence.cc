/* created   : 2020-11-23 21:11:59
 * accepted  : 2020-11-23 22:00:07
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(1 << N);
  vector<array<int, 2>> e(1 << N);
  for (int i = 0; i < 1 << N; i++) {
    int u = i / 2;
    int v = i & ((1 << N - 1) - 1);
    trace(bitset<8>(i), bitset<8>(u), bitset<8>(v));
    e[i] = {u, v};
    g[u].push_back(i);
    g[v].push_back(i);
  }
  vector<int> vis(1 << N);
  vector<int> ans;
  std::function<void(int)> dfs = [&](int u) {
    while (g[u].size()) {
      int i = g[u].back();
      g[u].pop_back();
      if (vis[i]) continue;
      vis[i] = 1;
      dfs(e[i][0] ^ e[i][1] ^ u);
      ans.push_back(i);
    }
  };
  dfs(0);
  trace(ans);
  for (int i = 0; i < N - 1; i++) {
    cout << 0;
  }
  for (int a : ans) {
    cout << a % 2;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
