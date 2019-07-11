//=============================================================
// Name        : 221b
// Date        : Sun Jun 30 16:07:18 CST 2019
// Accepted    : Sun Jun 30 16:12:04 CST 2019
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

int get(int x, int y) {
  vector<int> d(10);
  while (x) {
    d[x % 10] = 1;
    x /= 10;
  }
  while (y) {
    if (d[y % 10] == 1) {
      return 1;
    }
    y /= 10;
  }
  return 0;
}

void solve() {
  int x;
  cin >> x;
  int ans = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      ans += get(x, i);
      if (x / i != i) {
        ans += get(x, x / i);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
