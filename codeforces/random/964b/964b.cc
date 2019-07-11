//=============================================================
// Name        : 964b
// Date        : Sat Jun 29 17:32:08 CST 2019
// Accepted    : Sat Jun 29 17:35:26 CST 2019
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
  int n, a, b, c, t;
  cin >> n >> a >> b >> c >> t;
  trace(c, b);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (c > b) {
      ans += a + (t - x) * (c - b);
    } else {
      ans += a;
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
