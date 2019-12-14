/* created   : 2019-12-14 18:31:49
 * accepted  : 2019-12-14 19:21:43
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<vector<int>> dp(n + 2, vector<int>(n + 2));
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= n; j++) {
      if (a[i] == b[j]) {
        // int mx = 0;
        // for (int k = 0; k < j; k++) {
        //   if (b[k] < a[i]) {
        //     mx = max(mx, dp[i - 1][k]);
        //   }
        // }
        dp[i][j] = mx + 1;
      }
      else {
        dp[i][j] = dp[i - 1][j];
      }
      if (b[j] < a[i]) {
        mx = max(mx, dp[i - 1][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
