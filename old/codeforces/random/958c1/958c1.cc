/* created   : 2019-08-21 21:40:18
 * accepted  : 2019-08-21 21:44:14
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
  int n, p;
  cin >> n >> p;
  vector<ll> pr(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pr[i + 1] = pr[i] + x;
  }
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ll x = pr[i];
    ll y = pr[n] - pr[i];
    ll t = x % p + y % p;
    ans = max(ans, t);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
