/* created   : 2019-10-18 23:14:00
 * accepted  : 2019-10-18 23:24:54
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

struct combina {
  // c(n, k) = c(n - 1, k) + c(n - 1, k - 1);
  vector<vector<ll>> dp;
  combina(int n) {
    dp.resize(n + 1, vector<ll>(n + 1));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= i; k++) {
        dp[i][k] = dp[i - 1][k] + dp[i - 1][k - 1];
      }
    }
  }
  // Choose k from total n items without permutation
  ll operator() (int n, int k) {
    return dp[n][k];
  }
};

void solve() {
  ll n, m, t; cin >> n >> m >> t;
  ll ans = 0;
  combina cnk(40);
  for (int i = 4; i <= n; i++) {
    if (1 <= t - i && t - i <= m) {
      ans += cnk(n, i) * cnk(m, t - i);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
