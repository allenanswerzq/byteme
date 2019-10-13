/* created   : 2019-10-14 00:36:33
 * accepted  : 2019-10-14 00:45:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int md = 1e9 + 7;
inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

const int N = 120;
int v[N][N][30];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    for (int j = 0; j < m; j++) {
      v[i][j][x[j] - 'A'] = 1;
    }
  }
  vector<int> g(m);
  for (int j = 0; j < m; j++) {
    int cnt = 0;
    for (int k = 0; k < 26; k++) {
      bool ok = 0;
      for (int i = 0; i < n; i++) {
        if (v[i][j][k]) {
          ok = 1;
          break;
        }
      }
      cnt += (ok == 1);
    }
    g[j] = cnt;
  }
  trace(g);
  ll ans = 1;
  for (int i = 0; i < m; i++) {
    ans = mul(ans, g[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
