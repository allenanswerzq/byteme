/* created   : 2019-10-07 21:54:49
 * accepted  : 2019-10-07 22:04:46
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

struct key {
  int cost;
  int unlock;
};

void solve() {
  int n, m; cin >> n >> m;
  vector<key> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].cost;
    int b; cin >> b;
    int unlock = 0;
    for (int j = 0; j < b; j++) {
      int x; cin >> x;
      x--;
      unlock |= (1 << x);
    }
    v[i].unlock = unlock;
  }
  const int INF = (1 << 30);
  vector<int> dp(1 << n, INF);
  dp[0] = 0;
  for (auto key : v) {
    for (int state = 0; state < (1 << n); state++) {
      int nstate = state | key.unlock;
      // trace(nstate, state, key.unlock);
      dp[nstate] = min(dp[nstate], dp[state] + key.cost);
    }
  }
  trace(dp);
  int ans = dp[(1 << n) - 1];
  cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
