/* created   : 2019-08-18 16:46:33
 * accepted  : 2019-08-18 17:25:37
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
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(n));
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    a[x][y].x = 1;
    a[x][y].y = i;
  }
  int ans = 1 << 30;
  for (int i = 0; i + 3 <= n; i++) {
    for (int j = 0; j + 3 <= n; j++) {
      int cnt = 0;
      int cur = -1;
      for (int k = 0; k < 3; k++) {
        for (int h = 0; h < 3; h++) {
          if (a[i + k][j + h].x) {
            cnt++;
            cur = max(cur, a[i + k][j + h].y);
          }
        }
      }
      if (cnt == 9) {
        ans = min(ans, cur);
      }
    }
  }
  cout << (ans == 1 << 30 ? -1 : ans + 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
