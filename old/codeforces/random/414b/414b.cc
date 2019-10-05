/* created   : 2019-09-02 23:39:05
 * accepted  : 2019-09-02 23:55:47
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int mod = 1e9 + 7;

void solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> dp(k + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    dp[1][i] = 1;
  }
  vector<vector<int>> d(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) {
        d[i].push_back(j);
      }
    }
  }
  for (int i = 2; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      for (auto v : d[j]) {
        dp[i][j] += dp[i - 1][v];
        dp[i][j] %= mod;
      }
    }
  }
  // trace(dp);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[k][i];
    ans %= mod;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
