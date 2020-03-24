/* created   : 2020-03-22 12:48:42
 * accepted  : 2020-03-22 13:30:18
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100;
int a[N][N];
int f[N][2000];

void solve() {
  int n, k, p; cin >> n >> k >> p;
  memset(a, 0, sizeof(a));
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= k; j++) {
      int x; cin >> x;
      sum += x;
      a[i][j] = sum;
    }
  }
  trace(mt(a, n + 1, k + 1));
  for (int i = 1; i <= n; i++) {
    for (int y = 1; y <= p; y++) {
      int cur = f[i - 1][y];
      for (int x = 1; x <= y; x++) {
        cur = max(cur, f[i - 1][y - x] + a[i][x]);
      }
      f[i][y] = cur;
    }
  }
  trace(mt(f, n + 1, p + 1));
  cout << f[n][p] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
