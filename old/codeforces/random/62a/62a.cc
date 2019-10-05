/* created   : 2019-08-17 16:37:21
 * accepted  : 2019-08-17 21:06:59
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
  int a, b;
  cin >> a >> b;
  int c, d;
  cin >> c >> d;
  if ((b - 1 <= c && c <= 2 * (b + 1)) || (a - 1 <= d && d <= 2 * (a + 1))) {
    cout << "YES" << '\n';
  }
  else {
    cout << "NO" << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
