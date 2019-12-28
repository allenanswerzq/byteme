/* created   : 2019-12-28 13:20:32
 * accepted  : 2019-12-28 13:52:28
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

const int N = 1240;
int f[N][N];
ll pr[N];
int a[N];
int n;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) {
    f[i][i] = 0;
    pr[i] = pr[i - 1] + a[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      for (int k = l; k + 1 <= r; k++) {
        amin(f[l][r], f[l][k] + f[k + 1][r]);
      }
      f[l][r] += pr[r] - pr[l - 1];
    }
  }
  trace(mt(f[1], n + 1));
  cout << f[1][n] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
