/* created   : 2019-10-06 17:18:05
 * accepted  : 2019-10-06 18:58:31
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
  int n, k; cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    int x; cin >> x;
    for (int j = 1; j <= x; j++) {
      int y; cin >> y;
      if (y == j) {
        cnt++;
      }
    }
  }
  cout << 2 * (n - cnt) - (k - 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
