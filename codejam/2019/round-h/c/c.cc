/* created   : 2019-11-17 14:20:38
 * accepted  : 2019-11-17 15:09:52
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
  // 5578
  // 1100
  // 0100
  string s;
  for (int i = 1; i <= 9; i++) {
    int x; cin >> x;
    s += string(x, (char)('0' + i));
  }
  trace(s);
  // dp[i][plus]
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
