/* created   : 2019-08-18 09:51:10
 * accepted  : 2019-08-18 10:40:27
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
  int w, h;
  cin >> w >> h;
  w++, h++;
  ll ans = 0;
  for (int i = 1; i < w - 1; i++) {
    for (int j = 1; j < h - 1; j++) {
      int x = min(i, w - i - 1);
      int y = (h - j) / 2;
      ans += x * y;
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
