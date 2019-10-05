//=============================================================
// Name        : 1059b
// Date        : Mon Jun 17 19:27:05 CST 2019
// Accepted    : Mon Jun 17 20:53:09 CST 2019
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
  vector<string> b(n, string(m, '.'));
  auto fix = [&](int i, int j) {
    int cnt = 0;
    for (int x = 0; x < 3; ++x) {
      for (int y = 0; y < 3; ++y) {
        if (x == 1 && y == 1) {
          continue;
        }
        cnt += (a[i + x][j + y] == '#');
      }
    }
    if (cnt == 8) {
      for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
          if (x == 1 && y == 1) {
            continue;
          }
          b[i + x][j + y] = '#';
        }
      }
    }
  };
  for (int i = 0; i < n - 2; ++i) {
    for (int j = 0; j < m - 2; ++j) {
      fix(i, j);
    }
  }
  trace(a, b);
  cout << (b == a ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
