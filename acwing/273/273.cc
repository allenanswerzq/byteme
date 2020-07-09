/* created   : 2020-07-09 16:55:36
 * accepted  : 2020-07-09 17:14:56
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 2e3 + 7;
const int INF = 1e9 + 7;
int f[N][N];
int a[N];
int b[N];
int n;

int go() {
  // f[i][j] = min(f[i - 1][k]) + abs(a[i] - b[j]) (1 <= k && k <= j)
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int mi = f[i - 1][0];
    for (int j = 1; j <= n; j++) {
      // int mi = INF;
      // for (int k = 1; k <= j; k++) { // NOTE: Loop ends at `j`.
      //   mi = min(mi, f[i - 1][k]);
      // }
      mi = min(mi, f[i - 1][j]);
      f[i][j] = mi + abs(a[i] - b[j]);
    }
  }
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, f[n][i]);
  }
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  int ans = go();
  reverse(b + 1, b + n + 1);
  ans = min(ans, go());
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
