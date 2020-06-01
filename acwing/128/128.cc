/* created   : 2020-06-01 21:58:17
 * accepted  : 2020-06-01 22:40:37
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 110;
int a[N][N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  trace(mt(a, n + 1, n + 1));
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      a[i][j] += a[i - 1][j];
    }
  }
  trace(mt(a, n + 1, n + 1));
  const int INF = 1e9;
  int mx = -INF;
  for (int l = 1; l <= n; l++) {
    for (int len = 1; l + len - 1 <= n; len++) {
      int r = l + len - 1;
      int cur = -INF;
      int sum = 0;
      for (int j = 1; j <= n; j++) {
        sum += a[r][j] - a[l - 1][j];
        cur = max(cur, sum);
        sum = max(sum, 0);
      }
      mx = max(mx, cur);
    }
  }
  cout << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
