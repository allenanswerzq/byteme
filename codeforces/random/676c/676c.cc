/* created   : 2019-09-07 00:18:27
 * accepted  : 2019-09-07 10:50:22
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
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    int lo = 0;
    int hi = 0;
    int t = k;
    while (hi < n) {
      if (s[hi] == 'a' + i) {
        hi++;
        ans = max(ans, hi - lo);
      }
      else if (t > 0) {
        hi++, t--;
        ans = max(ans, hi - lo);
      }
      else {
        if (s[lo] == 'b' + (i ? -1 : 0)) {
          t++;
        }
        lo++;
        ans = max(ans, hi - lo + 1);
      }
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
