/* created   : 2020-02-07 16:41:23
 * accepted  : 2020-02-07 17:13:54
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

void solve() {
  int p, y; cin >> p >> y;
  for (int i = y; i > p; i--) {
    bool ok = false;
    for (int j = 2; j <= min(p, 100000); j++) {
      if (i % j == 0) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << i << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
