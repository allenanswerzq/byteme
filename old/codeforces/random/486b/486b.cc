/*
 * Creat   : Sun Jul 14 11:26:07 CST 2019
 * Accept  : Sun Jul 14 11:53:58 CST 2019
 * Author  : landcold7
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
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> b(n, vector<int>(m, 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 0) {
        for (int k = 0; k < n; ++k) {
          b[k][j] = 0;
        }
        for (int k = 0; k < m; ++k) {
          b[i][k] = 0;
        }
      }
    }
  }
  trace(b);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x = 0;
      for (int k = 0; k < n; ++k) {
        x += (b[k][j] == 1);
      }
      for (int k = 0; k < m; ++k) {
        x += (b[i][k] == 1);
      }
      if (a[i][j] != (x > 0)) {
        cout << "NO" << "\n";
        return;
      }
    }
  }
  cout << "YES" << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << b[i][j] << (j == m - 1 ? "\n" : " ");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
