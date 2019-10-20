/* created   : 2019-10-19 21:32:50
 * accepted  : 2019-10-20 10:03:44
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

void solve() {
  int n, m, q; cin >> n >> m >> q;
  vector<int> page(n + 1, 1);
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    assert(0 <= x && x <= n);
    page[x] = 0;
  }
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = i; j <= n; j += i) {
      cnt += (page[j] == 1);
    }
    dp[i] = cnt;
  }
  ll ans = 0;
  for (int i = 0; i < q; i++) {
    int x; cin >> x;
    ans += dp[x];
  }
  cout << ans << '\n';
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
