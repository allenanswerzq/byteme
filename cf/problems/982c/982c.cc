/* created   : 2019-10-20 19:35:36
 * accepted  : 2019-10-20 20:15:37
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

const int N = 2e5 + 7;
vector<int> g[N];
int dp[N];
int n;

void dfs(int u, int pr = -1) {
  dp[u] = 1;
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, u);
      dp[u] += dp[v];
    }
  }
}

void solve() {
  cin >> n;
  if (n % 2 == 1) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0);
  trace(mt(dp, n));
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (dp[i] % 2 == 0) {
      ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
