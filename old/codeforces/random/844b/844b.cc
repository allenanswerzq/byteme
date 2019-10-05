//=============================================================
// Name        : 844b
// Date        : Fri Jun 28 16:35:10 CST 2019
// Accepted    : Fri Jun 28 16:52:24 CST 2019
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
  vector<vector<int>> row(2, vector<int>(n));
  vector<vector<int>> col(2, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      row[x][i]++;
      col[x][j]++;
    }
  }
  trace(row, col);
  ll ans = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      int x = row[i][j];
      ans += (1ll << x) - 1;
    }
    for (int j = 0; j < m; ++j) {
      int x = col[i][j];
      ans += (1ll << x) - 1;
    }
  }
  cout << ans - n * m << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
