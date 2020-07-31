/* created   : 2020-07-31 07:33:42
 * accepted  : 2020-07-31 07:50:33
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 3837;
int f[2][N][2];
int a[N];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(f, -0x3f, sizeof(f));
  f[1][0][0] = f[1][1][1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      // If not sleep at i
      f[i & 1][j][0] = max(f[(i - 1) & 1][j][0], f[(i - 1) & 1][j][1]);
      // If sleep at i
      if (j) {
        f[i & 1][j][1] = max(f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + a[i]);
      }
    }
  }
  int ans = max(f[n & 1][m][0], f[n & 1][m][1]);
  memset(f, -0x3f, sizeof(f));
  f[1][0][0] = 0;
  f[1][1][1] = a[1];
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      // If not sleep at i
      f[i & 1][j][0] = max(f[(i - 1) & 1][j][0], f[(i - 1) & 1][j][1]);
      // If sleep at i
      if (j) {
        f[i & 1][j][1] = max(f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + a[i]);
      }
    }
  }
  ans = max(ans, f[n & 1][m][1]);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
