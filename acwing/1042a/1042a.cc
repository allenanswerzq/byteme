/* created   : 2019-12-16 23:46:56
 * accepted  : 2019-12-17 00:05:00
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

// 0-1 knapsack
void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  // f[i][x] = (f[i - 1][x], f[i - 1][x - w]);
  vector<int> f(m + 1);
  f[0] = 1;
  // stage
  for (int i = 1; i <= n; i++) {
    // state
    for (int j = m; j >= 0; j--) {
      if (j >= a[i]) {
        // action
        f[j] = f[j] + f[j - a[i]];
      }
    }
  }
  trace(f);
  cout << f[m] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
