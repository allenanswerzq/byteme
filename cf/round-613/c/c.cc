/* created   : 2020-01-10 22:43:10
 * accepted  : 2020-01-10 23:18:40
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

ll lcm(ll a, ll b) {
  return (ll) a / __gcd(a, b) * b;
}

void solve() {
  ll x; cin >> x;
  ll best = 1e12 + 7;
  pair<ll, ll> ans;
  for (ll a = 1; a * a <= x; a++) {
    if (x % a == 0 && lcm(a, x / a) == x) {
      ll cur = max(a, (ll) (x / a));
      trace(a, x / a);
      if (best > cur) {
        cur = best;
        ans = {a, x / a};
      }
    }
  }
  cout << ans.x << " " << ans.y << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
