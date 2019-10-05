//=============================================================
// Name        : 732c
// Date        : Thu Jun  6 17:19:52 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  vector<ll> a(3);
  ll mx = 0;
  int ix = -1;
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
    if (mx < a[i]) {
      mx = a[i], ix = i;
    }
  }
  // arrive 4 choices: | b | d | s |
  // left 4 choices: | b | d | s |
  trace(mx, ix);
  ll ans = 0;
  for (int i = 0; i < 3; ++i) {
    if (i != ix) {
      ans += max(0ll, a[ix] - 1 - a[i]);
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
