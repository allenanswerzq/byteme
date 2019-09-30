/* created   : 2019-09-08 10:57:08
 * accepted  : 2019-09-08 11:18:52
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
  int n, m; cin >> n >> m;
  int ans = min(n, m) + 1;
  cout << ans << '\n';
  int x = 0, y = m;
  for (int i = 0; i < ans; i++) {
    cout << x << ' ' << y << '\n';
    x++, y--;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
