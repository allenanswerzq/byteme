//=============================================================
// Name        : 828b
// Date        : Wed Jun 26 11:54:56 CST 2019
// Accepted    : Wed Jun 26 12:29:58 CST 2019
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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> x, y;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'B') {
        x.push_back(i);
        y.push_back(j);
      }
    }
  }
  int black = (int) x.size();
  int ans = 0;
  if (black == 0) {
    ans = 1;
  } else if (black == 1) {
    ans = 0;
  } else {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    trace(x, y);
    int mx = x.back() - x[0] + 1;
    int my = y.back() - y[0] + 1;
    mx = max(mx, my);
    if (mx > min(n, m)) {
      ans = -1;
    } else {
      ans = mx * mx - black;
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
