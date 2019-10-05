//=============================================================
// Name        : 40a
// Date        : Sun Jul  7 15:19:02 CST 2019
// Accepted    : Sun Jul  7 15:39:12 CST 2019
// Author      : landcold7
// Description : Action speaks louder more than words
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
  int x, y;
  cin >> x >> y;
  int a = x * x + y * y;
  int d = floor(sqrt(a));
  trace(d, a, sqrt(a));
  bool ok = 0;
  int s = (x > 0) ^ (y > 0);
  if (d * d == a) {
    ok = 1;
  }
  else if (d % 2 == 0) {
    ok = (!s ? 1 : 0);
  }
  else {
    ok = (!s ? 0 : 1);
  }
  cout << (!ok ? "white" : "black") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
