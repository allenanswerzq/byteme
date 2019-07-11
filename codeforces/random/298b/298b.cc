//=============================================================
// Name        : 298b
// Date        : Sun Jun 23 11:39:08 CST 2019
// Accepted    : Sun Jun 23 11:51:34 CST 2019
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
  int t, sx, sy, ex, ey;
  cin >> t >> sx >> sy >> ex >> ey;
  string s;
  cin >> s;
  for (int i = 0; i < sz(s); ++i) {
    if (s[i] == 'S' && ey < sy) {
      sy--;
    } else if (s[i] == 'E' && ex > sx) {
      sx++;
    } else if (s[i] == 'W' && ex < sx) {
      sx--;
    } else if (s[i] == 'N' && ey > sy) {
      sy++;
    }
    if (sx == ex && sy == ey) {
      cout << (i + 1 <= t ? i + 1 : -1) << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
