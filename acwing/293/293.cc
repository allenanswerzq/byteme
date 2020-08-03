/* created   : 2020-08-03 06:24:38
 * accepted  : 2020-08-03 07:05:59
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 12;
ll f[N][1 << N];
int a[1 << N];
int n;
int m;

void solve() {
  for (int i = 0; i < 1 << m; i++) {
    int cnt = 0, odd = 0;
    for (int j = 0; j < m; j++) {
      if (i >> j & 1) {
        odd |= (cnt & 1);
        cnt = 0;
      }
      else {
        // count the number of zeros.
        cnt++;
      }
    }
    a[i] = odd | (cnt & 1) ? 0 : 1;
  }
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 1 << m; j++) {
      f[i][j] = 0;
      for (int k = 0; k < 1 << m; k++) {
        if ((j & k) == 0 && a[j | k]) {
          f[i][j] += f[i - 1][k];
        }
      }
    }
  }
  cout << f[n][0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n >> m && n && m) {
    solve();
  }
  return 0;
}
