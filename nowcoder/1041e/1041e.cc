/* created   : 2019-12-17 00:14:45
 * accepted  : 2019-12-17 01:00:22
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

void amax(int& a, int b) {
  a = max(a, b);
}

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
  f[0][1][1] = 0;
  for (int i = 1; i <= n + m - 2; i++) {
    for (int x1 = 1; x1 <= n; x1++) {
      for (int x2 = 1; x2 <= n; x2++) {
        int cur = f[i - 1][x1][x2];
        int y1 = i + 2 - x1;
        int y2 = i + 2 - x2;
        if (x1 == x2) {
          // right, right
          amax(f[i][x1][x2], cur + a[y1 - 1][y1]);
          // down down
          amax(f[i][x1][x2], cur + a[x1 - 1][x1]);
        }
        else {
          // right, down
          amax(f[i][x1][x2], cur + a[y1 - 1][y1] + a[x2 - 1][x2]);
          // down, right
          amax(f[i][x1][x2], cur + a[x1 - 1][x1] + a[y2 - 1][y2]);
        }
      }
    }
  }
  cout << f[n + m - 2][n][n] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
