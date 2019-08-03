/*
 * created   : 2019-07-29 09:48:37
 * accepted  : 2019-07-29 10:01:39
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
  char c;
  cin >> n >> m >> c;
  vector<pair<int, int>> a;
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
    for (int j = 0; j < m; j++) {
      if (g[i][j] == c) {
        a.emplace_back(i, j);
      }
    }
  }
  trace(a);
  auto check = [&](int x, int y) {
    for (auto t : a) {
      if (abs(x - t.x) + abs(y - t.y) == 1) {
        return true;
      }
    }
    return false;
  };
  int ans = 0;
  vector<char> use(256);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (g[i][j] != '.' && g[i][j] != c && !use[g[i][j]]) {
        if (check(i, j)) {
          use[g[i][j]] = 1;
          ans++;
        }
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
