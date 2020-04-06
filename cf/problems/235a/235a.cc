/* created   : 2020-04-05 22:39:52
 * accepted  : 2020-04-05 23:49:40
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n; cin >> n;
  ll ans = 0;
  for (ll i = max(1ll, min(n - 10, n)); i <= n; i++) {
    for (ll j = i; j <= n; j++) {
      for (ll k = j; k <= n; k++) {
        ll x = i * j / __gcd(i, j);
        ll y = x * k / __gcd(x, k);
        ans = max(ans, y);
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
