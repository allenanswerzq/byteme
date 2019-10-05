//=============================================================
// Name        : c
// Date        : Mon Jun 10 10:19:03 CST 2019
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
  vector<int> was(n + 1);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    was[x] = 1;
  }
  const int mod = 1e9 + 7;
  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (was[i]) {
      dp[i] = 0;
    }
    else {
      dp[i] += dp[i - 1] % mod;
      if (i >= 2) {
        dp[i] += dp[i - 2] % mod;
      }
      dp[i] %= mod;
    }
  }
  trace(was, dp);
  cout << dp[n] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
