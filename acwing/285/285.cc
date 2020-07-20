/* created   : 2020-07-20 07:33:01
 * accepted  : 2020-07-20 08:15:52
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void amax(int& a, int b) { a = max(a, b); }

void amin(int& a, int b) { a = min(a, b); }

const int N = 120;
const int INF = 32768;
int f[N][N];
int g[N][N];
char op[N];
int a[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> op[i];
    cin >> a[i];
    op[i + n] = op[i];
    a[i + n] = a[i];
  }
  for (int len = 1; len <= n; len++) {
    for (int l = 1; l + len - 1 <= 2 * n; l++) {
      int r = l + len - 1;
      if (len == 1) {
        f[l][r] = a[l];
        g[l][r] = a[l];
      }
      else {
        f[l][r] = -INF;
        g[l][r] = INF;
        for (int k = l; k < r; k++) {
          if (op[k + 1] == 't') {
            amax(f[l][r], f[l][k] + f[k + 1][r]);
            amin(g[l][r], g[l][k] + g[k + 1][r]);
          }
          else {
            amax(f[l][r], f[l][k] * f[k + 1][r]);
            amax(f[l][r], f[l][k] * g[k + 1][r]);
            amax(f[l][r], g[l][k] * g[k + 1][r]);
            amax(f[l][r], g[l][k] * f[k + 1][r]);
            amin(g[l][r], f[l][k] * f[k + 1][r]);
            amin(g[l][r], f[l][k] * g[k + 1][r]);
            amin(g[l][r], g[l][k] * g[k + 1][r]);
            amin(g[l][r], g[l][k] * f[k + 1][r]);
          }
        }
      }
    }
  }
  int ans = -INF;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f[i][i + n - 1]);
  }
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) {
    if (ans == f[i][i + n - 1]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
