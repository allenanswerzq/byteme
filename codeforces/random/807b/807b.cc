//=============================================================
// Name        : 807b
// Date        : Sun Jun 30 15:27:07 CST 2019
// Accepted    : Sun Jun 30 16:04:50 CST 2019
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

bool check(int score, int place) {
  int x = (score / 50) % 475;
  for (int i = 0; i < 25; ++i) {
    x = (x * 96 + 42) % 475;
    if (26 + x == place) {
      return true;
    }
  }
  return false;
}

void solve() {
  int p, x, y;
  cin >> p >> x >> y;
  const int maxn = 2e5 + 7;
  for (int i = y; i < maxn; ++i) {
    int t = i - x;
    if (t % 50 == 0 && check(i, p)) {
      // x + 100 * a - b * 50 = i;
      // 50 * (2 a - b) = i - x;
      // trace(i, x);
      t = t / 50;
      t = max(0, (t + 1) / 2);
      cout << t << "\n";
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
