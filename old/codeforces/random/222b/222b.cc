//=============================================================
// Name        : 222b
// Date        : Sat Jun 29 17:41:30 CST 2019
// Accepted    : Sat Jun 29 17:48:01 CST 2019
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
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<int> row(n), col(m);
  iota(row.begin(), row.end(), 0);
  iota(col.begin(), col.end(), 0);
  for (int i = 0; i < k; ++i) {
    char op;
    int x, y;
    cin >> op >> x >> y;
    x--, y--;
    if (op == 'r') {
      swap(row[x], row[y]);
    }
    else if (op == 'c') {
      swap(col[x], col[y]);
    }
    else {
      cout << a[row[x]][col[y]] << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
