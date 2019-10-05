/* created   : 2019-08-20 19:36:07
 * accepted  : 2019-08-20 23:59:33
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
  for (int i = 0; i < n; i++) {
    int s, f, t;
    cin >> s >> f >> t;
    ll ans = t;
    if (s < f) {
      int y = 2 * (m - 1);
      int x = (t - (s - 1) + y - 1) / y;
      ans = y * x + s - 1 + f - s;
    }
    else if (s > f) {
      int y = m - 1;
      int x = (t - (m - s) + 3 * y - 1) / (2 * y);
      ans = y * (2 * x - 1) + (m - s) + s - f;
    }
    else if (s == f) {
      ans = t;
    }
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
