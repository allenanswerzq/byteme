/* created   : 2020-03-06 22:30:43
 * accepted  : 2020-03-07 14:57:42
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

ll add(ll x, ll d) {
  ll t = min(x, d);
  ll ans = t * (x + x - t + 1) / 2 + (d - t);
  trace(x, d, ans);
  return ans;
}

void solve() {
  int n, m, k; cin >> n >> m >> k;
  auto check = [&](ll x) {
    ll bed = add(x, k);
    bed += add(x, n - k + 1);
    bed -= x;
    trace(x, bed, m);
    return bed <= m;
  };
  int lo = 1;
  int hi = m;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    if (check(md)) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  trace(lo, hi);
  cout << (check(hi) ? hi : lo) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
