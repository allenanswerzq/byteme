//=============================================================
// Name        : 631b
// Date        : Wed Jun 19 09:29:46 CST 2019
// Accepted    : Wed Jun 19 09:36:45 CST 2019
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> row(n), col(m);
  for (int i = 0; i < k; ++i) {
    int t, p, c;
    cin >> t >> p >> c;
    p--;
    if (t == 1) {
      row[p] = {c, i + 1};
    } else {
      col[p] = {c, i + 1};
    }
  }
  trace(row, col);
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (row[i].second > col[j].second) {
        a[i][j] = row[i].first;
      } else {
        a[i][j] = col[j].first;
      }
    }
  }
  trace(a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j] << (j == m - 1 ? "\n" : " ");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
