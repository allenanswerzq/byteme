//=============================================================
// Name        : 729b
// Date        : Wed Jun 26 16:24:19 CST 2019
// Accepted    : Wed Jun 26 17:09:14 CST 2019
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
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    bool ok = 0;
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 0 && ok) {
        ans++;
      }
      if (a[i][j] == 1) {
        ok = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    bool ok = 0;
    for (int j = m; j >= 1; --j) {
      if (a[i][j] == 0 && ok) {
        ans++;
      }
      if (a[i][j] == 1) {
        ok = 1;
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    bool ok = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i][j] == 0 && ok) {
        ans++;
      }
      if (a[i][j] == 1) {
        ok = 1;
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    bool ok = 0;
    for (int i = n; i >= 1; --i) {
      if (a[i][j] == 0 && ok) {
        ans++;
      }
      if (a[i][j] == 1) {
        ok = 1;
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
