/* created   : 2020-07-21 07:58:15
 * accepted  : 2020-07-21 08:10:16
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int mod = 1e9;
const int N = 320;
int f[N][N];

void solve() {
  string a; cin >> a;
  a = "@" + a;
  int n = a.size() - 1;
  for (int len = 1; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      if (len == 1) {
        f[l][r] = 1;
      }
      else {
        for (int k = l; k < r; k++) {
          if (a[l] == a[k] && a[k] == a[r]) {
            f[l][r] += (ll)f[l][k] * f[k + 1][r - 1] % mod;
            f[l][r] %= mod;
          }
        }
      }
    }
  }
  cout << f[1][n] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
