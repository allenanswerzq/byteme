/* created   : 2019-12-15 17:16:44
 * accepted  : 2019-12-15 20:39:11
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

void amin(int& a, int b) {
  a = min(a, b);
}

const int N = 1010;
const int L = 220;
const int INF = 0x3f3f3f3f;
int l;
int n;
int c[L][L];
int f[N][L][L];
int p[N];

void solve() {
  cin >> l >> n;
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= l; j++) {
      cin >> c[i][j];
    }
  }
  memset(f, 0x3f, sizeof(f));
  p[0] = 3;
  f[0][1][2] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    for (int j = 1; j <= l; j++) {
      for (int k = 1; k <= l; k++) {
        if (k != p[i] && j != p[i]) {
          amin(f[i][j][k], f[i - 1][j][k] + c[p[i - 1]][p[i]]);
        }
        if (k != p[i] && p[i - 1] != p[i]) {
          amin(f[i][p[i - 1]][k], f[i - 1][j][k] + c[j][p[i]]);
        }
        if (j != p[i] && p[i - 1] != p[i]) {
          amin(f[i][j][p[i - 1]], f[i - 1][j][k] + c[k][p[i]]);
        }
      }
    }
  }
  trace(mt(f[n], l + 1, l + 1), ttt);
  int ans = INF;
  for (int x = 1; x <= l; x++) {
    for (int y = 1; y <= l; y++) {
      ans = min(ans, f[n][x][y]);
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
