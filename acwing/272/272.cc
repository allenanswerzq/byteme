/* created   : 2020-07-08 18:56:23
 * accepted  : 2020-07-08 19:14:16
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 3e3 + 7;
int a[N];
int b[N];
int f[N][N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= n; j++) {
      if (a[i] == b[j]) {
        // int mx = 0;
        // for (int k = 0; k < j; k++) {
        //   if (b[k] < a[i]) {
        //     mx = max(mx, f[i - 1][k]);
        //   }
        // }
        f[i][j] = mx + 1;
      }
      else {
        f[i][j] = f[i - 1][j];
      }
      if (b[j] < a[i]) {
        // NOTE: here we must use `i - 1`.
        mx = max(mx, f[i - 1][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f[n][i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
