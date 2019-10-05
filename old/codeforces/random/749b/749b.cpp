//=============================================================
// Name        : 749b
// Date        : Sun Jun  9 09:57:15 CST 2019
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
  vector<pair<int, int>> a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  vector<pair<int, int>> ans(3);
  ans[0] = {
    a[1].x - a[2].x + a[0].x,
    a[1].y - a[2].y + a[0].y,
  };
  ans[1] = {
    a[0].x - a[1].x + a[2].x,
    a[0].y - a[1].y + a[2].y,
  };
  ans[2] = {
    a[2].x - a[0].x + a[1].x,
    a[2].y - a[0].y + a[1].y,
  };
  cout << 3 << "\n";
  for (int i = 0; i < 3; ++i) {
    cout << ans[i].x << " " << ans[i].y << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
