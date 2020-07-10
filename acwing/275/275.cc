/* created   : 2020-07-10 15:01:41
 * accepted  : 2020-07-10 15:30:36
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void amax(int& a, int b) { a = max(a, b); }

const int N = 52;
int f[120][N][N];
int a[N][N];

void solve() {
  int m, n; cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int k = 1; k <= m + n; k++) {
    for (int x1 = 1; x1 <= m; x1++) {
      for (int x2 = 2; x2 <= m; x2++) {
        int y1 = k - x1;
        int y2 = k - x2;
        if (!(1 <= y1 && y1 <= n && 1 <= y2 && y2 <= n)) continue;
        int add = a[x1][y1] + a[x2][y2];
        // (1,1) --> (x1, y1 - 1) --> (x1, y1) right
        // (1,1) --> (x2, y2 - 1) --> (x2, y2) right
        amax(f[k][x1][x2], f[k - 1][x1][x2] + add);
        // (1,1) --> (x1, y1 - 1) --> (x1, y1) right
        // (1,1) --> (x2 - 1, y2) --> (x2, y2) down
        amax(f[k][x1][x2], f[k - 1][x1][x2 - 1] + add);
        // (1,1) --> (x1 - 1, y1) --> (x1, y1) down
        // (1,1) --> (x2 - 1, y2) --> (x2, y2) down
        amax(f[k][x1][x2], f[k - 1][x1 - 1][x2 - 1] + add);
        // (1,1) --> (x1 - 1, y1) --> (x1, y1) down
        // (1,1) --> (x2, y2 - 1) --> (x2, y2) right
        amax(f[k][x1][x2], f[k - 1][x1 - 1][x2] + add);
        if (x1 == x2) {
          // If add twice for a same position.
          f[k][x1][x2] -= a[x1][y1];
        }
      }
    }
  }
  int ans = 0;
  for (int k = 1; k <= m + n; k++) {
    ans = max(ans, f[k][m][m]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
