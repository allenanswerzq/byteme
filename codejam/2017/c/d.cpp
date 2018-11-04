#include<bits/stdc++.h>
using namespace std;

ll odd(ll mi, ll mx, ll me, ll md) {
  ll diff = mi + mx + md - me * 3;
  if (diff == 0) return 3;
  ll tmp = me * 2 - mi - md;
  if (diff < 0) {
    diff = -diff;
    tmp = mx + md - me * 2;
  }
  return (tmp <= 0) ? inf : ((diff - 1 + tmp) / tmp + 1) * 2 + 3;
}

ll even(ll mi, ll mx, ll me, ll md) {
  if (me * 2 == mi + mx && md == me) return 2;
  ll diff = mi + mx + md * 2 - me * 4;
  if (diff == 0) return 4;
  ll tmp = me * 2 - mi - md;
  if (diff < 0) {
    diff = -diff;
    tmp = mx + md - me * 2;
  }
  return (tmp <= 0) ? inf : ((diff - 1 + tmp) / tmp) * 2 + 4;
}

ll solve() {
  ll mi, mx, me, md;
  cin >> mi >> mx >> me >> md;
  bool ok = (me >= mi && me <= mx && md >= mi && md <= mx);
  if (!ok) return inf;
  if (mi == mx) return 1;
  ll ans = min(odd(mi, mx, me, md), even(mi, mx, me, md));
  return ans;
}

int main() {
 
  ll t; cin >> t;
  fori (i, 1, t + 1) {
    ll r = solve();
    if (r == inf)
      output(i, "IMPOSSIBLE");     
    else 
      output(i, r);
  }

  return 0;
}
