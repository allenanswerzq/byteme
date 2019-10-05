//=============================================================
// Name        : 820b
// Date        : Thu Jun 27 20:29:23 CST 2019
// Accepted    : Thu Jun 27 21:13:30 CST 2019
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
  int n, a;
  cin >> n >> a;
  double deg = (n - 2) * 180.0 / n;
  double unit = deg / (n - 2);
  double mi = (1 << 30);
  int ix = -1;
  for (int i = 1; i <= (n - 2); ++i) {
    if (fabs(unit * i - a) < mi) {
      mi = fabs(unit * i - a);
      ix = i;
    }
  }
  trace(mi, ix);
  cout << 2 << " " << 1 << " " << (2 + ix) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
