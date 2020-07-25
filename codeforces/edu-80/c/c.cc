/* created   : 2020-01-14 23:00:02
 * accepted  : 2020-01-15 10:49:32
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
#endif
typedef long long ll;

const int mod = 1e9 + 7;
const int N = 1e3 + 7;
int f[N];
int g[N];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    g[i] = 1;
  }
  for (int i = 2; i <= 2 * m; i++) {
    for (int j = 1; j <= n; j++) {
      f[j] = 0;
      for (int k = j; k >= 1; k--) {
        f[j] += g[k] % mod;
        f[j] %= mod;
      }
    }
    swap(f, g);
  }
  // trace(mt(f, 2 * m + 1, n + 1));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += g[i] % mod;
    ans %= mod;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
