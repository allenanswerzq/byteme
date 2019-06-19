//=============================================================
// Name        : 485b
// Date        : Tue Jun 18 11:29:06 CST 2019
// Accepted    : Tue Jun 18 11:30:48 CST 2019
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
  int n;
  cin >> n;
  vector<int> x, y;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    x.push_back(a);
    y.push_back(b);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int sx = x[n - 1] - x[0];
  int sy = y[n - 1] - y[0];
  int mx = max(sx, sy);
  cout << mx * 1ll * mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
