//=============================================================
// Name        : 216a
// Date        : Sat Jun 29 16:17:57 CST 2019
// Accepted    : Sat Jun 29 17:04:45 CST 2019
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
  int a, b, c;
  cin >> a >> b >> c;
  int ans = (b + a - 1) * (c + a - 1) - a * (a - 1);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
