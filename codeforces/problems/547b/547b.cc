/* created   : 2019-10-20 13:28:27
 * accepted  : 2019-10-20 14:29:42
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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> deg(n);
  vector<vector<int>> g(n, vector<int>(n));
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    g[x][y] = 1;
    g[y][x] = 1;
    deg[x]++;
    deg[y]++;
    edges.emplace_back(x, y);
  }
  int ans = 1 << 30;
  for (auto e : edges) {
    for (int i = 0; i < n; i++) {
      if (i != e.x && i != e.y && g[e.x][i] && g[e.y][i]) {
        ans = min(ans, deg[e.x] + deg[e.y] + deg[i]);
      }
    }
  }
  cout << (ans == 1 << 30 ? -1 : ans - 6) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
