//=============================================================
// Name        : 821b
// Date        : Wed Jun 26 09:46:01 CST 2019
// Accepted    : Wed Jun 26 09:50:57 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

ll go(ll x) {
  return x * (x + 1) / 2;
}

void solve() {
  ll m, b;
  cin >> m >> b;
  ll ans = 0;
  for (ll x = 0; x <= b * m; ++x) {
    if (x % m == 0) {
      ll y = - x / m + b;
      ll s = (x + 1) * go(y) + go(x) * (y + 1);
      ans = max(ans, s);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
