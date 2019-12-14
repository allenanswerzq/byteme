/* created   : 2019-12-14 16:55:42
 * accepted  : 2019-12-14 17:55:04
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

void solve() {
  vector<int> a(5);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll f[a[0] + 1][a[1] + 1][a[2] + 1][a[3] + 1][a[4] + 1];
  memset(f, 0, sizeof(f));
  f[0][0][0][0][0] = 1;
  for (int i = 0; i <= a[0]; i++) {
    for (int j = 0; j <= a[1]; j++) {
      for (int k = 0; k <= a[2]; k++) {
        for (int w = 0; w <= a[3]; w++) {
          for (int h = 0; h <= a[4]; h++) {
            ll cur = f[i][j][k][w][h];
            if (i < a[0])          f[i + 1][j][k][w][h] += cur;
            if (j < a[1] && j < i) f[i][j + 1][k][w][h] += cur;
            if (k < a[2] && k < j) f[i][j][k + 1][w][h] += cur;
            if (w < a[3] && w < k) f[i][j][k][w + 1][h] += cur;
            if (h < a[4] && h < w) f[i][j][k][w][h + 1] += cur;
          }
        }
      }
    }
  }
  cout << f[a[0]][a[1]][a[2]][a[3]][a[4]] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n && n) {
    solve();
  }
  return 0;
}
