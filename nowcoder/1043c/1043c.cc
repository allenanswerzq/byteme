/* created   : 2019-12-29 10:52:19
 * accepted  : 2019-12-30 11:39:41
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

const int mod = 1e9;
const int N = 320;
int f[N][N];
char s[N];

void solve() {
  scanf("%s", s + 1);
  int n = 0;
  for (int i = 1; i < 320 && s[i]; i++) {
    n++;
  }
  for (int i = 1; i <= n; i++) {
    f[i][i] = 1;
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      if (s[l] == s[r]) {
        for (int k = l + 2; k <= r; k++) {
          if (s[l] == s[k]) {
            f[l][r] += (ll) f[l + 1][k - 1] * f[k][r] % mod;
            f[l][r] %= mod;
          }
        }
      }
    }
  }
  cout << f[1][n] % mod << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}


