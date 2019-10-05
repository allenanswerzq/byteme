//=============================================================
// Name        : 353a
// Date        : Wed Jun  5 15:11:48 CST 2019
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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  int sa = 0, sb = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    sa += a[i].x;
    sb += a[i].y;
  }
  int ret = 0;
  if (sa % 2 == 1 && sb % 2 == 1) {
    bool ok = 0;
    for (int i = 0; i < n; ++i) {
      int x = sa - a[i].x + a[i].y;
      int y = sb - a[i].y + a[i].x;
      if (x % 2 == 0 && y % 2 == 0) {
        ok = 1;
        break;
      }
    }
    if (ok) {
      ret = 1;
    } else {
      ret = -1;
    }
  } else if (sa % 2 == 0 && sb % 2 == 0) {
    ret = 0;
  } else {
    ret = -1;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
