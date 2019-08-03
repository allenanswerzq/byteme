/*
 * created   : 2019-07-22 15:56:40
 * accepted  : 2019-07-22 19:07:03
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  const int N = 1e5 + 7;
  vector<int> dp(n + 1);
  vector<bool> cnt(N);
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = dp[i];
    if (!cnt[a[i]]) {
      dp[i + 1]++;
    }
    cnt[a[i]] = true;
  }
  trace(dp);
  fill(cnt.begin(), cnt.end(), 0);
  ll ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (!cnt[a[i]]) {
      ans += dp[i];
    }
    cnt[a[i]] = true;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
