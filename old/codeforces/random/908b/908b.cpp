//=============================================================
// Name        : 908b
// Date        : Fri Jun  7 15:46:52 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
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
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  pair<int, int> start, exit;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'S') {
        start = {i, j};
      } else if (a[i][j] == 'E') {
        exit = {i, j};
      }
    }
  }
  vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  auto check = [&](vector<int> mp) {
    pair<int, int> tmp = start;
    for (int i = 0; i < (int) s.size(); ++i) {
      auto d = dir[mp[s[i] - '0']];
      tmp.x += d.x, tmp.y += d.y;
      if (!(0 <= tmp.x && tmp.x < n && 0 <= tmp.y && tmp.y < m)) {
        return false;
      }
      if (a[tmp.x][tmp.y] == '#') {
        return false;
      }
      if (tmp == exit) {
        return true;
      }
    }
    return false;
  };
  vector<int> mp(4);
  iota(mp.begin(), mp.end(), 0);
  int ans = 0;
  do {
    if (check(mp)) {
      ans++;
    }
  } while (next_permutation(mp.begin(), mp.end()));
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
