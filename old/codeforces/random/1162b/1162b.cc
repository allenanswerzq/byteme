/*
 * created   : 2019-08-04 11:27:27
 * accepted  : 2019-08-04 12:14:25
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
      if (a[i][j] > b[i][j]) {
        swap(a[i][j], b[i][j]);
      }
    }
  }
  auto check = [&](vector<vector<int>>& x) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 1; j++) {
        if (x[i][j] >= x[i][j + 1]) {
          return false;
        }
      }
    }
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n - 1; i++) {
        if (x[i][j] >= x[i + 1][j]) {
          return false;
        }
      }
    }
    return true;
  };
  cout << (check(a) && check(b) ? "Possible" : "Impossible") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
