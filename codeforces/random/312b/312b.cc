//=============================================================
// Name        : 312b
// Date        : Wed Jun 19 17:12:10 CST 2019
// Accepted    : Wed Jun 19 17:29:41 CST 2019
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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  double p = a * 1.0 / b;
  double q = (1 - a * 1.0 / b) * (1 - c * 1.0 / d);
  double ans = p / (1 - q);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(20) << "\n";
  solve();
  return 0;
}
