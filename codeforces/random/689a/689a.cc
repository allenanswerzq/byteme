/*
 * created   : 2019-07-28 09:53:46
 * accepted  : 2019-07-28 20:58:43
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
  vector<vector<int>> a = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {-1, 0, -1},
  };
  auto get = [&](char x) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (a[i][j] == x - '0') {
          return pair<int, int>(i, j);
        }
      }
    }
    assert(false);
    return pair<int, int>(-1, -1);
  };
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int, int>> seq;
  pair<int, int> o = get(s[0]);
  for (int i = 1; i < n; ++i) {
    pair<int, int> t = get(s[i]);
    seq.emplace_back(t.x - o.x, t.y - o.y);
  }
  trace(seq);
  auto check = [&](int x, int y) {
    if (a[x][y] == -1) {
      return false;
    }
    for (auto t : seq) {
      int xx = x + t.x;
      int yy = y + t.y;
      if (!(0 <= xx && xx < 4 && 0 <= yy && yy < 3)) {
        return false;
      }
      if (a[xx][yy] == -1) {
        return false;
      }
    }
    return true;
  };
  int cnt = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (check(i, j)) {
        cnt++;
      }
    }
  }
  cout << (cnt == 1 ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
