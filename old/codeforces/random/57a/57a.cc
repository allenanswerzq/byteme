/* created   : 2019-08-20 09:42:07
 * accepted  : 2019-08-20 11:02:06
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
  int n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  int ans = 0;
  while (x1 != x2 || y1 != y2) {
    ans++;
    if (x1 == 0 && y1 < n) {
      y1++;
    }
    else if (x1 < n && y1 == n) {
      x1++;
    }
    else if (x1 == n && y1 > 0) {
      y1--;
    }
    else if (x1 > 0 && y1 == 0) {
      x1--;
    }
  }
  cout << min(ans, 4 * n - ans) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
