/* created   : 2020-01-08 23:13:35
 * accepted  : 2020-01-09 23:59:30
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

void amax(int& a, int b) { a = max(a, b); }

const int N = 4000;
int f[2][N][2];
int a[N];
int n;
int m;

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(f, 0x80, sizeof(f));
  f[1 & 1][0][0] = 0;
  f[1 & 1][1][1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      amax(f[i & 1][j][0], f[(i - 1) & 1][j][0]);
      amax(f[i & 1][j][0], f[(i - 1) & 1][j][1]);
      if (j >= 1) {
        amax(f[i & 1][j][1], f[(i - 1) & 1][j - 1][0]);
        amax(f[i & 1][j][1], f[(i - 1) & 1][j - 1][1] + a[i]);
      }
    }
  }
  int ans = max(f[n & 1][m][0], f[n & 1][m][1]);
  trace(ans);
  memset(f, 0x80, sizeof(f));
  f[1 & 1][1][1] = a[1];

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      amax(f[i & 1][j][0], f[(i - 1) & 1][j][0]);
      amax(f[i & 1][j][0], f[(i - 1) & 1][j][1]);
      if (j >= 1) {
        amax(f[i & 1][j][1], f[(i - 1) & 1][j - 1][0]);
        amax(f[i & 1][j][1], f[(i - 1) & 1][j - 1][1] + a[i]);
      }
    }
  }
  amax(ans, f[n & 1][m][1]);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
