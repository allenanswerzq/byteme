/* created   : 2019-10-27 23:07:58
 * accepted  : 2019-10-27 23:09:07
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int a, b; cin >> a >> b;
  if (1 <= a && a <= 9 && 1 <= b && b <= 9) {
    cout << a * b << '\n';
  }
  else {
    cout << -1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
