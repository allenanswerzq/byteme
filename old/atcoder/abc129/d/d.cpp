//=============================================================
// Name        : d
// Date        : Mon Jun 10 10:34:28 CST 2019
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

const int maxn = 2007;
char a[maxn][maxn];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i] + 1);
  }
  vector<vector<pair<int, int>>> dp(n + 2, vector<pair<int, int>>(m + 2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == '.') {
        dp[i][j].x = dp[i][j - 1].x + 1;
        dp[i][j].y = dp[i - 1][j].y + 1;
      }
    }
  }
  vector<vector<pair<int, int>>> np(n + 2, vector<pair<int, int>>(m + 2));
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 1; --j) {
      if (a[i][j] == '.') {
        np[i][j].x += np[i][j + 1].x + 1;
        np[i][j].y += np[i + 1][j].y + 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (a[i][j] == '.') {
        dp[i][j].x += np[i][j].x;
        dp[i][j].y += np[i][j].y;
        ans = max(ans, dp[i][j].x + dp[i][j].y);
      }
    }
  }
  trace(dp, np);
  cout << ans - 3 << "\n";
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  solve();
  return 0;
}
