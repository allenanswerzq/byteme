/* created   : 2019-08-13 09:33:49
 * accepted  : 2019-08-13 09:42:28
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
  int n, m;
  cin >> n >> m;
  int x, y;
  cin >> x >> y;
  int k;
  cin >> k;
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    int dx, dy;
    cin >> dx >> dy;
    int step = (1 << 30);
    if (dy != 0) {
      step = min(step, (dy > 0 ? (m - y) : y - 1) / abs(dy));
    }
    if (dx != 0) {
      step = min(step, (dx > 0 ? (n - x) : x - 1) / abs(dx));
    }
    ans += step;
    x += dx * step;
    y += dy * step;
    trace(x, y);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
