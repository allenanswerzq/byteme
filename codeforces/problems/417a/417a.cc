/* created   : 2020-03-28 23:11:51
 * accepted  : 2020-03-29 00:18:17
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
#define xuyixuyi()
#endif
typedef long long ll;

void solve() {
  int c, d; cin >> c >> d;
  int n, m; cin >> n >> m;
  int k; cin >> k;
  int ans = 1e9 + 7;
  for (int x = 0; x <= 100000; x++) {
    int y = n * m - k - x * n;
    if (y >= 0) {
      ans = min(ans, x * c + y * d);
    }
    else {
      ans = min(ans, x * c);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
