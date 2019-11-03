/* created   : 2019-10-30 00:36:13
 * accepted  : 2019-10-30 10:17:04
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 625;
vector<int> g[N];
int n;
int m;

vector<double> expect(const pair<int, int>& ignore) {
  vector<double> dp(n);
  for (int u = n - 2; u >= 0; u--) {
    double cur = 0;
    int cnt = 0;
    for (auto v : g[u]) {
      if (u == ignore.x && v == ignore.y) {
        continue;
      }
      cnt++;
      cur += dp[v];
    }
    dp[u] = cur / cnt + 1;
  }
  return dp;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  vector<double> dp = expect({-1, -1});
  trace(dp);
  double ans = dp[0];
  for (int u = 0; u < n - 1; u++) {
    if (g[u].size() <= 1) {
      continue;
    }
    double mx = 0;
    int ix = -1;
    for (auto v : g[u]) {
      if (dp[v] > mx) {
        mx = dp[v];
        ix = v;
      }
    }
    vector<double> np = expect({u, ix});
    ans = min(ans, np[0]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(10) << fixed;
  solve();
  return 0;
}
