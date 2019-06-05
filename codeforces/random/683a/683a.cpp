//=============================================================
// Name        : 683a
// Date        : Wed Jun  5 10:23:09 CST 2019
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
  int a, x, y;
  cin >> a >> x >> y;
  int ret = -1;
  if (0 < x && x < a && 0 < y && y < a) {
    ret = 0;
  } else if (y == 0 || y == a || x == 0 || x == a) {
    ret = 1;
  } else {
    ret = 2;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
