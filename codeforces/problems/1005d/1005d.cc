/* created   : 2019-11-25 08:36:23
 * accepted  : 2019-11-26 08:37:50
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
  string s; cin >> s;
  int n = s.size();
  vector<int> dp(n + 1);
  vector<int> last(3, -1);
  last[0] = 0;
  int rem = 0;
  for (int i = 1; i <= n; i++) {
    rem = (rem + s[i - 1] - '0') % 3;
    dp[i] = dp[i - 1];
    if (last[rem] != -1) {
      dp[i] = max(dp[i], dp[last[rem]] + 1);
    }
    last[rem] = i;
  }
  cout << dp[n] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
