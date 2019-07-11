//=============================================================
// Name        : 1068a
// Date        : Thu Jun 27 08:58:35 CST 2019
// Accepted    : Thu Jun 27 09:28:07 CST 2019
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

void solve() {
  ll n, m, k, l;
  cin >> n >> m >> k >> l;
  if (k + l > n) {
    cout << -1 << "\n";
    return;
  }
  ll lo = 0, hi = n / m;
  if (hi * m - k < l) {
    cout << -1 << "\n";
    return;
  }
  while (hi - lo > 1) {
    ll md = lo + (hi - lo) / 2;
    if (md * m - k >= l) {
      hi = md;
    } else {
      lo = md;
    }
  }
  cout << hi << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
