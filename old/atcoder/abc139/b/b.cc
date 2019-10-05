/* created   : 2019-09-04 00:19:31
 * accepted  : 2019-09-04 00:44:25
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
  int a, b; cin >> a >> b;
  int ans = (b - 1 + a - 2) / (a - 1);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
