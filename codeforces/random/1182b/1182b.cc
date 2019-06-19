//=============================================================
// Name        : 1182b
// Date        : Tue Jun 18 10:53:06 CST 2019
// Accepted    : Tue Jun 18 11:10:15 CST 2019
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
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
  auto check = [&](int r, int c) {
    if (a[r][c] != '*') {
      return false;
    }
    for (auto d : dir) {
      int x = r + d.first;
      int y = c + d.second;
      if (!(0 <= x && x < n && 0 <= y && y < m) || a[x][y] == '.') {
        return false;
      }
    }
    return true;
  };
  auto up = [&](int r, int c) {
    for (int i = r - 1; i >= 0 && a[i][c] == '*'; --i) {
      a[i][c] = '.';
    }
  };
  auto down = [&](int r, int c) {
    for (int i = r + 1; i < n && a[i][c] == '*'; ++i) {
      a[i][c] = '.';
    }
  };
  auto left = [&](int r, int c) {
    for (int i = c - 1; i >= 0 && a[r][i] == '*'; --i) {
      a[r][i] = '.';
    }
  };
  auto right = [&](int r, int c) {
    for (int i = c + 1; i < m && a[r][i] == '*'; ++i) {
      a[r][i] = '.';
    }
  };
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (check(i, j)) {
        a[i][j] = '.';
        up(i, j);
        down(i, j);
        left(i, j);
        right(i, j);
        cnt++;
        break;
      }
    }
  }
  trace(a);
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '*') {
        ok = false;
        break;
      }
    }
  }
  cout << (cnt == 1 && ok ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
