//=============================================================
// Name        : 376b
// Date        : Sun Jun 30 22:00:44 CST 2019
// Accepted    : Sun Jun 30 23:02:02 CST 2019
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
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x][y] = z;
  }
  trace(a);
  for (int h = 0; h < n; ++h) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= n; ++k) {
          if (a[i][j] > 0 && a[j][k] > 0) {
            int x = min(a[i][j], a[j][k]);
            a[i][j] -= x;
            a[j][k] -= x;
            a[i][k] += x;
          }
        }
      }
    }
    trace(a);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans += a[i][j];
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
