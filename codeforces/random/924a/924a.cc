/*
 * created   : 2019-07-29 22:16:31
 * accepted  : 2019-07-29 23:14:38
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
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  auto check = [&](int x, int y) {
    vector<int> a, b;
    for (int i = 0; i < m; i++) {
      if (g[x][i] == '#') {
        a.push_back(i);
      }
      if (g[y][i] == '#') {
        b.push_back(i);
      }
    }
    if (a == b) {
      return true;
    }
    for (auto t : a) {
      for (auto v : b) {
        if (t == v) {
          return false;
        }
      }
    }
    return true;
  };
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!check(i, j)) {
        trace(i, j);
        cout << "No" << "\n";
        return;
      }
    }
  }
  cout << "Yes" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
