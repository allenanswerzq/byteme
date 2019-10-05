/* created   : 2019-08-18 16:12:30
 * accepted  : 2019-08-18 16:22:39
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
  int n;
  cin >> n;
  vector<vector<int>> g(10);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  auto check = [&](int i, int j, int k) {
    int x = 0;
    for (auto v : g[i]) {
      if (v == j || v == k) {
        x++;
      }
    }
    int y = 0;
    for (auto v : g[j]) {
      if (v == i || v == k) {
        y++;
      }
    }
    int z = 0;
    for (auto v : g[k]) {
      if (v == i || v == j) {
        z++;
      }
    }
    if (x == 2 && y == 2 && z == 2) {
      return true;
    }
    if (x == 0 && y == 0 && z == 0) {
      return true;
    }
    return false;
  };
  for (int i = 1; i <= 5; i++) {
    for (int j = i + 1; j <= 5; j++) {
      for (int k = j + 1; k <= 5; k++) {
        if (check(i, j, k)) {
          cout << "WIN" << '\n';
          return;
        }
      }
    }
  }
  cout << "FAIL" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
