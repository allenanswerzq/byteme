/* created   : 2020-07-11 09:31:38
 * accepted  : 2020-07-11 10:03:09
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

void amin(int& a, int b) { a = min(a, b); }

const int N = 32;
const int M = 5200;
const int INF = 1e9 + 7;
int f[N][M];
pii g[N];
int ps[N];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> g[i].x;
    g[i].y = i;
  }
  sort(g + 1, g + 1 + n);
  reverse(g + 1, g + 1 + n);
  for (int i = 1; i <= n; i++) {
    ps[i] = ps[i - 1] + g[i].x;
  }
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j >= i) {
        // zero kids will get 1 cookie.
        f[i][j] = f[i][j - i];
      }
      for (int k = 1; k <= min(i, j); k++) {
        // k kids will get 1 cookies.
        int cur = (ps[i] - ps[i - k]) * (i - k);
        amin(f[i][j], f[i - k][j - k] + cur);
      }
    }
  }
  cout << f[n][m] << "\n";
  vector<int> path(n + 1);
  int i = n, j = m, cookie = 0;
  while (i && j) {
    if (j >= i && f[i][j] == f[i][j - i]) {
      j -= i, cookie++;
    }
    else {
      for (int k = 1; k <= min(i, j); k++) {
        int cur = (ps[i] - ps[i - k]) * (i - k);
        if (f[i][j] == f[i - k][j - k] + cur) {
          for (int u = i; u > i - k; u--) {
            path[g[u].y] = 1 + cookie;
          }
          i -= k, j -= k;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << path[i] << (i == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
