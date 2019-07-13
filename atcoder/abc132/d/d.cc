//=============================================================
// Name        : d
// Date        : Thu Jul  4 09:41:30 CST 2019
// Accepted    : Thu Jul  4 09:59:37 CST 2019
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

const int mod = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  const int maxn = 2400;
  vector<vector<int>> dp(maxn, vector<int>(maxn));
  for (int i = 0; i < maxn; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      dp[i][j] %= mod;
    }
  }
  for (int i = 1; i <= k; ++i) {
    int r = n - k;
    int x = dp[r + 1][i];
    int y = dp[k - 1][i - 1];
    cout << ((ll)x * y % mod) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
