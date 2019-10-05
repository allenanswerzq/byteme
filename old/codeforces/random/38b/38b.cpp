//=============================================================
// Name        : 38b
// Date        : Tue Jun  4 14:49:29 CST 2019
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
typedef vector<int> vi;

void solve() {
  string a, b;
  cin >> a >> b;
  int x1, y1, x2, y2;
  x1 = a[0] - 'a' + 1;
  y1 = a[1] - '0';
  x2 = b[0] - 'a' + 1;
  y2 = b[1] - '0';
  auto dist = [](int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  };
  int ret = 0;
  for (int x3 = 1; x3 <= 8; ++x3) {
    for (int y3 = 1; y3 <= 8; ++y3) {
      if (x1 == x3 || y1 == y3) {
        continue;
      }
      if (x2 == x3 && y2 == y3) {
        continue;
      }
      if (dist(x1, y1, x3, y3) != 5) {
        if (dist(x2, y2, x3, y3) != 5) {
          ret++;
        }
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
