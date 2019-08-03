/*
 * created   : 2019-07-21 14:49:53
 * accepted  : 2019-07-21 15:41:57
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  auto get = [&](int r) {
    int one = 0;
    int mx = 0;
    for (int j = 0; j < m; ++j) {
      if (a[r][j] == 1) {
        one++;
      }
      else {
        mx = max(mx, one);
        one = 0;
      }
    }
    mx = max(mx, one);
    return mx;
  };
  vector<int> row(n);
  for (int i = 0; i < n; ++i) {
    row[i] = get(i);
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    a[x][y] ^= 1;
    row[x] = get(x);
    trace(x, y, row, a);
    cout << *max_element(row.begin(), row.end()) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
