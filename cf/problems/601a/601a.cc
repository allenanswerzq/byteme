/* created   : 2020-04-06 23:59:51
 * accepted  : 2020-04-07 00:52:49
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int n, m;

int bfs(vector<vector<int>>& g) {
  deque<pair<int, int>> dq;
  dq.push_back({0, 0});
  vector<bool> use(n);
  use[0] = true;
  while (!dq.empty()) {
    auto u = dq.front();
    dq.pop_front();
    if (u.x == n - 1) {
      return u.y;
    }
    for (auto v : g[u.x]) {
      if (!use[v]) {
        use[v] = true;
        dq.push_back({v, u.y + 1});
      }
    }
  }
  return -1;
}

void solve() {
  cin >> n >> m;
  vector<vector<int>> railway(n);
  vector<vector<bool>> connect(n, vector<bool>(n));
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    connect[u][v] = true;
    connect[v][u] = true;
    railway[u].push_back(v);
    railway[v].push_back(u);
  }
  vector<vector<int>> road(n);
  for (int u = 0; u < n; u++) {
    for (int v = u + 1; v < n; v++) {
      if (!connect[u][v]) {
        road[u].push_back(v);
        road[v].push_back(u);
      }
    }
  }
  trace(road);
  int x = bfs(road);
  int y = bfs(railway);
  trace(x, y);
  if (x == -1 || y == -1) {
    cout << -1 << '\n';
  }
  else {
    cout << max(x, y) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
