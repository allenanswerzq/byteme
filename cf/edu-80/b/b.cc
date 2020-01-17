/* created   : 2020-01-14 22:46:06
 * accepted  : 2020-01-15 00:06:14
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

// 6 * 9 + 6 + 9 = 69
// 12
// (d * h) % 10 + (d + h) % 10 = h
//                             = g
// b = (conc(a, b) - a - b) / a
// b = [conc(a, b) - b] / a - 1
// b = 1000? - 1

// 100 * 100 = 100100
// a(b + 1) + b + 1 - 1
// (a + 1)(b + 1) = conc(a, b) = ab + 1
void solve() {
  ll a, b; cin >> a >> b;
  ll ans = 0;
  for (int i = 0; ; i++) {
    ll y = 10;
    int x = i;
    while (x--) {
      y *= 10;
    }
    if (y - 1 <= b) {
      ans += a;
    }
    else {
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
