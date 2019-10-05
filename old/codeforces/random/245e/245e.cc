/* created   : 2019-08-17 22:58:22
 * accepted  : 2019-08-18 09:05:03
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
  string s;
  cin >> s;
  int ans = 0;
  int bag = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '-') {
      if (bag > 0) {
        bag--;
      }
      else {
        ans++;
      }
    }
    else {
      if (bag < ans) {
        bag++;
      }
      else {
        bag++;
        ans++;
      }
    }
    trace(i, bag, ans);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
