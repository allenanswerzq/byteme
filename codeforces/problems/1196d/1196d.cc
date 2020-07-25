/* created   : 2019-10-06 10:08:51
 * accepted  : 2019-10-06 12:19:12
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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  const string v = "RGB";
  int ans = (1 << 30);
  for (int i = 0; i < 3; i++) {
    vector<int> dp(n);
    int cur = 0;
    for (int j = 0; j < n; j++) {
      dp[j] = (s[j] != v[(j + i) % 3]);
      cur += dp[j];
      if (j >= k) {
        cur -= dp[j - k];
      }
      if (j >= k - 1) {
        ans = min(ans, cur);
      }
    }
  }
  cout << ans << '\n';
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
