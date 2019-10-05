//=============================================================
// Name        : 463a
// Date        : Thu Jun  6 10:29:35 CST 2019
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
  int n, s;
  cin >> n >> s;
  int ans = 0;
  bool ok = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if ((x < s) || (x == s && y == 0)) {
      ok = 1;
    }
    if (x < s && y > 0) {
      ans = max(ans, 100 - y);
    }
  }
  cout << (ok ? ans : -1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
