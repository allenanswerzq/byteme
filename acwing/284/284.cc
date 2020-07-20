/* created   : 2020-07-20 07:09:17
 * accepted  : 2020-07-20 07:17:35
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void amin(int& a, int b) { a = min(a, b); }

const int N = 320;
const int INF = 1e9;
int a[N];
int s[N];
int f[N][N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
    cin >> a[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      f[l][r] = INF;
      for (int k = l; k < r; k++) {
        amin(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
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
