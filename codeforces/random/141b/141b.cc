/* created   : 2019-08-11 09:36:49
 * accepted  : 2019-08-11 10:15:05
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
  int a, y, x;
  cin >> a >> y >> x;
  int h = x / a;
  if (h == 0) {
    int ans = -1;
    if (0 < x && x < a && abs(y) < a * 1.0 / 2) {
      ans = 1;
    }
    cout << ans << "\n";
    return;
  }
  int ans = -1;
  int t = (h - 1) / 2;
  if ((h - 1) % 2 == 0) {
    if (h * a < x && x < (h + 1) * a && abs(y) < a * 1.0 / 2) {
      ans = 2 * t + (h - t) + 1;
    }
  }
  else {
    if (h * a < x && x < (h + 1) * a && -a < y && y < 0) {
      ans = 2 * t + (h - t) + 1;
    }
    else if (h * a < x && x < (h + 1) * a && 0 < y && y < a) {
      ans = 2 * t + (h - t) + 2;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
