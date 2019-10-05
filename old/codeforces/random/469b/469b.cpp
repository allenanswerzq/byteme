//=============================================================
// Name        : 469b
// Date        : Mon Jun 10 15:26:07 CST 2019
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
  int n, m, l, r;
  cin >> n >> m >> l >> r;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  vector<pair<int, int>> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i].x >> b[i].y;
  }
  trace(n, m, l, r);
  int ans = 0;
  for (int i = l; i <= r; ++i) {
    for (auto t : b) {
      t.x += i, t.y += i;
      bool ok = 0;
      for (auto z : a) {
        if (z.x <= t.x && t.x <= z.y) {
          ans++, ok = 1;
          break;
        } else if (t.x <= z.x && z.x <= t.y) {
          ans++, ok = 1;
          break;
        }
      }
      if (ok) {
        break;
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
