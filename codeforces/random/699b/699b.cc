/*
 * creat   : 2019-07-18 21:18:31
 * accept  : 2019-07-18 21:47:30
 * author  : landcold7
 */
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
  vector<string> a(n);
  int tot = 0;
  vector<int> row(n);
  vector<int> col(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '*') {
        tot++;
        row[i]++;
        col[j]++;
      }
    }
  }
  if (tot == 0) {
    cout << "YES" << "\n";
    cout << 1 << " " << 1 << "\n";
    return;
  }
  trace(tot, row, col);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (row[i] + col[j] - (a[i][j] == '*') == tot) {
        cout << "YES" << "\n";
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
