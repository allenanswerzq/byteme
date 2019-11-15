/* created   : 2019-11-15 08:11:15
 * accepted  : 2019-11-15 11:23:07
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

ll total(ll x) {
  if (x == 0) {
    return 0;
  }
  return (1ll << (64 - __builtin_clzll(x))) - 1;
}

ll go(ll n, ll x) {
  if (x == 0) {
    return 0;
  }
  ll half = n / 2;
  ll tot = total(half);
  if (x <= tot) {
    return go(half, x);
  }
  else {
    return half + (n % 2) + go(half, x - tot - 1);
  }
}

void solve() {
  ll n, l, r; cin >> n >> l >> r;
  cout << go(n, r) - go(n, l - 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
