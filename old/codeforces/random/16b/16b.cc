//=============================================================
// Name        : 16b
// Date        : Thu Jun 27 10:45:15 CST 2019
// Accepted    : Thu Jun 27 10:49:14 CST 2019
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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i].y >> a[i].x;
  }
  sort(a.rbegin(), a.rend());
  trace(a);
  ll ans = 0;
  for (int i = 0; i < m && n > 0; ++i) {
    ans += min(n, a[i].y) * a[i].x;
    n -= min(n, a[i].y);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
