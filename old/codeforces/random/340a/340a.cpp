//=============================================================
// Name        : 340a
// Date        : Mon Jun 17 15:45:49 CST 2019
// Accepted    : Mon Jun 17 15:48:02 CST 2019
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
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  int g = x * y / __gcd(x, y);
  cout << (b / g - (a - 1) / g) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
