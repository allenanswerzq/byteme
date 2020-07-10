/* created   : 2019-12-17 00:14:45
 * accepted  : 2019-12-17 12:58:25
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

void amax(int& a, int b) { a = max(a, b); }

const int N = 52;
int n;
int m;
int a[N][N];
int f[120][N][N];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  memset(f, 0, sizeof(f));
  f[1][1][1] = 0;
  for (int i = 2; i <= n + m; i++) {
    for (int x1 = 1; x1 <= n; x1++) {
      for (int x2 = 1; x2 <= n; x2++) {
        int y1 = i - x1 + 1;
        int y2 = i - x2 + 1;
        if (y1 <= 0 || y2 <= 0 || y1 > m || y2 > m) {
          continue;
        }
        trace(i, x1, y1, x2, y2);
        int mx = 0;
        // right, right
        amax(mx, f[i - 1][x1][x2]);
        // down, down
        amax(mx, f[i - 1][x1 - 1][x2 - 1]);
        // right, down
        amax(mx, f[i - 1][x1][x2 - 1]);
        // down, right
        amax(mx, f[i - 1][x1 - 1][x2]);
        f[i][x1][x2] = mx + a[x1][y1] + a[x2][y2];
        if (x1 == x2) {
          f[i][x1][x2] -= a[x1][y1];
        }
      }
    }
  }
  cout << f[n + m - 1][n][n] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}
