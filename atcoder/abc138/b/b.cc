/* created   : 2019-08-29 00:22:08
 * accepted  : 2019-08-29 00:30:01
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
  int n; cin >> n;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    ans += 1.0 / x;
  }
  cout << 1.0 / ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
