/* created   : 2019-09-15 18:37:28
 * accepted  : 2019-09-15 22:53:17
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

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> v(n - 1);
  for (int i = 0; i < n - 1; i++) {
    v[i] = abs(a[i] - a[i + 1]);
  }
  trace(v);
  vector<vector<ll>> dp(n, vector<ll>(2));
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    // NOTE(zq7): maximum range sum
    dp[i][0] = max(dp[i - 1][1] + v[i - 1], v[i - 1]);
    dp[i][1] = dp[i - 1][0] - v[i - 1];
    ans = max(ans, max(dp[i][0], dp[i][1]));
  }
  trace(dp);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
