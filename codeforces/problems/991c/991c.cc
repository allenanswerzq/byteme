/* created   : 2019-10-14 23:59:07
 * accepted  : 2019-10-15 00:07:40
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

ll n;

bool check(ll k) {
  ll ea = 0;
  ll eb = 0;
  ll t = n;
  while (t > 0) {
    ea += min(k, t), t -= min(k, t);
    eb += t / 10, t -= t / 10;
  }
  return (ea >= (n + 1) / 2);
}

void solve() {
  cin >> n;
  ll lo = 1;
  ll hi = n;
  while (lo + 1 < hi) {
    ll md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << (check(lo) ? lo : hi) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
