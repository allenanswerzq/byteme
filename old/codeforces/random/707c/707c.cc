/* created   : 2019-09-08 16:32:36
 * accepted  : 2019-09-08 17:04:24
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
  // a * a + b * b = n * n
  // n * n + b * b = c * c
  ll n; cin >> n;
  if (n <= 2) {
  // x * x + 4 = y * y
  // x * x - 4 = y * y
    cout << -1 << '\n';
    return;
  }
  ll x, y;
  if (n % 2) {
    x = (n * n + 1) / 2;
    y = (n * n - 1) / 2;
  }
  else {
    x = (n * n / 4 + 1);
    y = x - 2;
  }
  cout << y << ' ' << x << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
