/* created   : 2019-08-11 20:20:23
 * accepted  : 2019-08-11 20:35:38
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

const int N = 1e5 + 7;
int dp[N][2];

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  dp[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    bool u = 'A' <= s[i - 1] && s[i - 1] <= 'Z';
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + (u == 1);
    dp[i][1] = dp[i - 1][1] + (u == 0);
  }
  cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
