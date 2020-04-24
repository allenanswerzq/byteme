/* created  : 2020-04-24 21:26:55
 * accepted  : 2020-04-24 22:44:17
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 120;

int f[12][N][N];

void solve() {
  int n, q, c;
  cin >> n >> q >> c;
  for (int i = 0; i < n; i++) {
    int x, y, s; cin >> x >> y >> s;
    f[s][x][y]++;
  }
  for (int p = 0; p <= c; p++) {
    for (int i = 1; i < N; i++) {
      for (int j = 1; j < N; j++) {
        f[p][i][j] += f[p][i - 1][j] + f[p][i][j - 1] - f[p][i - 1][j - 1];
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int t, x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    int ans = 0;
    for (int p = 0; p <= c; p++) {
      int bright = (p + t) % (c + 1);
      int cnt = f[p][x2][y2] - f[p][x1 - 1][y2] - f[p][x2][y1 - 1] + f[p][x1 - 1][y1 - 1];
      ans += bright * cnt;
    }
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
