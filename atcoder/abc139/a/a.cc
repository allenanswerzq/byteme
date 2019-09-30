/* created   : 2019-09-04 00:15:28
 * accepted  : 2019-09-04 00:16:04
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
  string s, t; cin >> s >> t;
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    if (s[i] == t[i]) {
      ans++;
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
