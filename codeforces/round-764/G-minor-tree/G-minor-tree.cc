/* created   : 2022-01-15 21:12:22
 * accepted  : 2022-01-16 09:24:16
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<ar>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v, w; cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector<int> seen(N);
  int ans = (1 << 30) - 1;
  std::function<void(int u)> dfs = [&](int u) {
    seen[u] = 1;
    for (auto [v, e] : g[u]) {
      if (seen[v]) continue;
      if ((e | ans) != ans) continue;
      if ((e & ans) != e) continue;
      dfs(v);
    }
  };
  for (int i = 29; i >= 0; i--) {
    // Remove this ith bit, and check if graph still connected.
    ans &= ~(1 << i);
    fill(all(seen), 0);
    dfs(0);
    bool ok = true;
    for (int j = 0; j < N; j++) {
      if (!seen[j]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      // Can not remove this ith bit
      ans |= (1 << i);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
