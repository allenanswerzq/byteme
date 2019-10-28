/* created   : 2019-10-27 23:12:22
 * accepted  : 2019-10-27 23:20:18
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

void solve() {
  ll n; cin >> n;
  vector<pair<ll, ll>> a;
  for (ll x = 1; x * x <= n; x++) {
    if (n % x == 0) {
      a.emplace_back(x, n / x);
    }
  }
  ll ans = 1ll << 61;
  for (auto t : a) {
    ans = min(ans, t.x - 1 + t.y - 1);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
