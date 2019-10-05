//=============================================================
// Name        : 976b
// Date        : Thu Jun 27 09:41:34 CST 2019
// Accepted    : Thu Jun 27 10:09:48 CST 2019
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
  ll n, m, k;
  cin >> n >> m >> k;
  if (k < n) {
    cout << k + 1 << " " << 1 << "\n";
    return;
  }
  k -= n;
  ll r = k / (m - 1);
  ll c = k % (m - 1);
  ll x, y;
  x = y = -1;
  if (r % 2 == 0) {
    x = n - r;
    y = 2 + c;
  } else {
    x = n - r;
    y = m - c;
  }
  assert(x != -1 && y != -1);
  cout << x << " " << y << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
