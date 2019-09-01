/* created   : 2019-08-21 16:51:49
 * accepted  : 2019-08-21 17:05:16
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
  int n;
  cin >> n;
  int x = n / 36;
  int y = n % 36;
  y += (y % 3 == 2);
  n = x * 36 + y;
  int a = n / 36;
  int b = (n % 36) / 3;
  cout << a << ' ' << b << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
