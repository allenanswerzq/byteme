/*
 * created   : 2019-07-21 15:51:08
 * accepted  : 2019-07-22 11:21:34
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
  int n, m;
  cin >> n >> m;
  string row, col;
  cin >> row >> col;
  auto check = [&](int r, int c) {
    vector<vector<bool>> was(n, vector<bool>(m));
    was[r][c] = 1;
    deque<pair<int, int>> dq;
    dq.emplace_back(r, c);
    while (!dq.empty()) {
      int x = dq.back().x;
      int y = dq.back().y;
      dq.pop_back();
      int nx = x;
      int ny = y;
      if (row[x] == '<') {
        ny--;
      }
      else {
        ny++;
      }
      if (0 <= ny && ny < m && !was[x][ny]) {
        was[x][ny] = 1;
        dq.emplace_back(x, ny);
      }
      if (col[y] == '^') {
        nx--;
      }
      else {
        nx++;
      }
      if (0 <= nx && nx < n && !was[nx][y]) {
        was[nx][y] = 1;
        dq.emplace_back(nx, y);
      }
    }
    for (int k = 0; k < n; ++k) {
      if (*min_element(was[k].begin(), was[k].end()) == 0) {
        return false;
      }
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!check(i, j)) {
        cout << "NO" << "\n";
        return;
      }
    }
  }
  cout << "YES" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
