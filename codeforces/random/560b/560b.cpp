//=============================================================
// Name        : 560b
// Date        : Tue Jun 11 20:04:30 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  vector<vector<int>> a(3);
  for (int i = 0; i < 3; ++i) {
    int x, y;
    cin >> x >> y;
    a[i].emplace_back(x);
    a[i].emplace_back(y);
  }
  trace(a);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      int t = (a[1][i] + a[2][j]);
      int h = max(a[1][1 - i], a[2][1 - j]);
      for (int k = 0; k < 2; ++k) {
        if (t <= a[0][k] && h <= a[0][1 - k]) {
          cout << "YES" << "\n";
          return;
        }
      }
    }
  }
  cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
