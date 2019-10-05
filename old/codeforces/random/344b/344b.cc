//=============================================================
// Name        : 344b
// Date        : Tue Jun 18 15:09:18 CST 2019
// Accepted    : Tue Jun 18 15:19:17 CST 2019
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
  int x = (a - b + c);
  if (x < 0 || x % 2 == 1) {
    cout << "Impossible" << "\n";
    return;
  }
  x /= 2;
  int y = a - x;
  int z = b - y;
  if (y >= 0 && z >= 0) {
    cout << y << " " << z << " " << x << "\n";
  } else {
    cout << "Impossible" << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
