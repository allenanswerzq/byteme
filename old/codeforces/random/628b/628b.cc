//=============================================================
// Name        : 628b
// Date        : Mon Jun 24 22:03:47 CST 2019
// Accepted    : Mon Jun 24 22:32:36 CST 2019
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
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<ll> dp(n);
  dp[0] = (s[0] - '0') % 4 == 0;
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1] + ((s[i] - '0') % 4 == 0);
    int x = (s[i - 1] - '0') * 10 + (s[i] - '0');
    if (x % 4 == 0) {
      dp[i] += i;
    }
  }
  trace(dp);
  cout << dp[n - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
