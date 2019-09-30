/*
 * creat   : 2019-07-17 15:12:36
 * accept  : 2019-07-18 11:11:45
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

int x;
int tc;

void solve() {
  tc++;
  vector<int> a;
  a.push_back(x);
  while (cin >> x && x != -1) {
    a.push_back(x);
  }
  int n = (int) a.size();
  vector<int> dp(n, 1);
  trace(a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] >= a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int ans = *max_element(dp.begin(), dp.end());
  if (tc > 1) {
    cout << "\n";
  }
  cout << "Test #" << tc << ":\n";
  cout << "  maximum possible interceptions: " << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  tc = 0;
  while (cin >> x && x != -1) {
    solve();
  }
  return 0;
}
