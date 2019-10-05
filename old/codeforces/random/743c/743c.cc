/* created   : 2019-09-12 00:25:42
 * accepted  : 2019-09-15 12:37:34
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
  // 2 / n - (y + x) / xy = 1 / z
  // (2xy - n(x + y)) / nxy = 1 / z
  // z = nxy / (2xy - n(x + y))
  ll n; cin >> n;
  for (int x = 1; x < 12345; x++) {
    for (int y = x + 1; y < 12345; y++) {
      ll t = n * x * y;
      ll v = 2 * x * y - n * (x + y);
      if (v > 0 && t % v == 0) {
        ll z = t / v;
        if (1 < z && z < 1e9 && x != y && y != z && x != z) {
          cout << x << ' ' << y << ' ' << z << '\n';
          return;
        }
      }
    }
  }
  cout << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
