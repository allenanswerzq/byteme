/* created   : 2019-10-18 23:25:28
 * accepted  : 2019-10-18 23:55:24
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

const int N = 2e5 + 7;
int dp[N][2];

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    if (v[i - 1] < 0) {
      dp[i][0] = dp[i - 1][1] + 1;
      dp[i][1] = dp[i - 1][0];
    }
    else {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1] + 1;
    }
  }
  trace(make_tuple(dp, n + 1, 2));
  ll neg = 0;
  ll pos = 0;
  for (int i = 0; i <= n; i++) {
    neg += dp[i][0];
    pos += dp[i][1];
  }
  cout << neg << ' ' << pos << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
