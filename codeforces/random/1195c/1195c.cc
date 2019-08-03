/*
 * creat   : 2019-07-20 15:50:50
 * accept  : 2019-07-20 16:08:11
 * author  : landcold7
 */
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
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  trace(a);
  vector<vector<ll>> dp(2, vector<ll>(n + 1));
  vector<ll> mx(2);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      dp[1 - j][i] = mx[j] + a[1 - j][i - 1];
    }
    for (int j = 0; j < 2; ++j) {
      mx[1 - j] = max(mx[1 - j], dp[1 - j][i]);
    }
  }
  trace(dp);
  cout << max(dp[1][n], dp[0][n]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
