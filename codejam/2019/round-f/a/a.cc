/* created   : 2019-10-09 00:08:25
 * accepted  : 2019-10-09 00:53:44
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

const int N = 120;
int cost[N][N];
int n, k;
int v[N];

void before() {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vector<int> cnt(1234);
      for (int w = i; w <= j; w++) {
        cnt[v[w]]++;
      }
      int mx = *max_element(cnt.begin(), cnt.end());
      cost[i][j] = j - i + 1 - mx;
    }
  }
}

void amin(int& a, int b) {
  a = min(a, b);
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  before();
  const int INF = (1 << 30);
  vector<vector<int>> dp(n, vector<int>(k + 1, INF));
  // dp(i, k) = min(dp(j, k - 1) + cost(j + 1, i));
  for (int i = 0; i <= k; i++) {
    dp[0][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    dp[i][0] = cost[0][i];
  }
  for (int w = 1; w <= k; w++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        amin(dp[i][w], dp[j][w - 1] + cost[j + 1][i]);
      }
    }
  }
  trace(dp);
  cout << dp[n - 1][k] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
