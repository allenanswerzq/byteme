/* created   : 2020-03-15 11:02:13
 * accepted  : 2020-03-15 15:37:27
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  double vp, vd, t, f, c;
  cin >> vp >> vd >> t >> f >> c;
  if (vd <= vp) {
    cout << 0 << '\n';
    return;
  }
  double pos = t * vp;
  double ans = 0;
  while (pos < c) {
    double x = pos / (vd - vp);
    pos += vp * x;
    if (pos >= c) {
      break;
    }
    ans++;
    pos += vp * (x + f);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
