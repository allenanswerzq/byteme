/* created   : 2019-09-22 16:11:02
 * accepted  : 2019-09-22 19:58:27
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
vector<pair<int, int>> g[N];
int n, m;
int use[N];

bool dfs(int u, int t, int col) {
  use[u] = 1;
  if (u == t) {
    return true;
  }
  for (auto v : g[u]) {
    if (v.y == col && !use[v.x]) {
      if (dfs(v.x, t, col)) {
        return true;
      }
    }
  }
  return false;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  int q; cin >> q;
  trace(q);
  for (int i = 0; i < q; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    int ans = 0;
    for (int col = 1; col <= 100; col++) {
      memset(use, 0, sizeof(use));
      if (dfs(x, y, col)) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
