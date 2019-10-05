/* created   : 2019-08-22 00:01:03
 * accepted  : 2019-08-22 00:31:25
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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  int a, b, c;
  cin >> a >> b >> c;
  // 0 -- i, i + 1 -- j, j + 1 -- m - 1
  auto col = [&](int x, int y) {
    vector<int> e(3);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (0 <= j && j <= x) {
          e[0] += g[i][j];
        }
        else if (x < j && j <= y) {
          e[1] += g[i][j];
        }
        else {
          e[2] += g[i][j];
        }
      }
    }
    vector<int> t = {a, b, c};
    sort(t.begin(), t.end());
    sort(e.begin(), e.end());
    return t == e;
  };
  auto row = [&](int x, int y) {
    vector<int> e(3);
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        if (0 <= i && i <= x) {
          e[0] += g[i][j];
        }
        else if (x < i && i <= y) {
          e[1] += g[i][j];
        }
        else {
          e[2] += g[i][j];
        }
      }
    }
    vector<int> t = {a, b, c};
    sort(t.begin(), t.end());
    sort(e.begin(), e.end());
    return t == e;
  };
  int ans = 0;
  for (int i = 0; i + 3 <= m; i++) {
    for (int j = i + 1; j + 2 <= m; j++) {
      if (col(i, j)) {
        ans++;
      }
    }
  }
  for (int i = 0; i + 3 <= n; i++) {
    for (int j = i + 1; j + 2 <= n; j++) {
      if (row(i, j)) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
