/* created   : 2019-09-22 15:14:19
 * accepted  : 2019-09-22 16:04:04
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

const int INF = 1e5;

void solve() {
  int n; cin >> n;
  int mix = -INF;
  int miy = -INF;
  int mxx = INF;
  int mxy = INF;
  for (int i = 0; i < n; i++) {
    int x, y, f1, f2, f3, f4;
    cin >> x >> y >> f1 >> f2 >> f3 >> f4;
    if (!f1) {
    // x -->
      mix = max(x, mix);
    }
    if (!f2) {
    // can not move up
      mxy = min(y, mxy);
    }
    if (!f3) {
    // can not move right
      mxx = min(x, mxx);
    }
    if (!f4) {
    // can not move down
      miy = max(y, miy);
    }
  }
  if (miy <= mxy && mix <= mxx) {
    cout << 1 << ' ' << mix << ' ' << miy << '\n';
  }
  else {
    cout << 0 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    solve();
  }
  return 0;
}
