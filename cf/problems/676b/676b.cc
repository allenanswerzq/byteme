/* created   : 2020-02-23 10:57:33
 * accepted  : 2020-02-23 11:20:30
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

const int N = 12;
double a[N][N];

void solve() {
  int n, t; cin >> n >> t;
  a[1][1] = t;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      double x = a[i - 1][j - 1];
      double y = a[i - 1][j];
      if (x > 1) {
        a[i][j] += (x - 1) / 2.0;
      }
      if (y > 1) {
        a[i][j] += (y - 1) / 2.0;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (a[i][j] >= 1) {
        ans++;
      }
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
