/* created   : 2019-10-07 06:40:38
 * accepted  : 2019-10-17 14:30:09
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

void amin(ll& x, ll y) {
  x = min(x, y);
}

void solve() {
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  const ll INF = (1ll << 60);
  vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
  dp[0][0] = b;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      amin(dp[i + 1][0], dp[i][0] + a + b);
      amin(dp[i + 1][1], dp[i][0] + 2 * (a + b));

      amin(dp[i + 1][0], dp[i][1] + 2 * a + b);
      amin(dp[i + 1][1], dp[i][1] + a + 2 * b);
    }
    else {
      amin(dp[i + 1][1], dp[i][0] + 2 * (a + b) + b);
      amin(dp[i + 1][1], dp[i][1] + a + 2 * b);
    }
  }
  trace(dp);
  cout << dp[n][0] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
