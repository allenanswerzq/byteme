//=============================================================
// Name        : 416b
// Date        : Mon Jun 24 17:01:57 CST 2019
// Accepted    : Mon Jun 24 17:23:17 CST 2019
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
  vector<vector<int>> cost(n + 1, vector<int>(m + 2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> cost[i][j];
    }
  }
  trace(cost);
  vector<vector<int>> start(n + 1, vector<int>(m + 2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m + 1; ++j) {
      start[i][j] = max(start[i - 1][j] + cost[i - 1][j], start[i][j - 1] + cost[i][j - 1]);
    }
  }
  trace(start);
  for (int i = 1; i <= n; ++i) {
    cout << start[i][m + 1] << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
