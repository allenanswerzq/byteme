/* created   : 2019-09-15 12:37:07
 * accepted  : 2019-09-15 12:58:18
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
vector<int> g[N];
bool use[N];
bool cycle;
bool branch;

void dfs(int u, int pr) {
  if (use[u]) {
    cycle = true;
    return;
  }
  if ((int) g[u].size() != 2) {
    branch = true;
  }
  use[u] = true;
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, u);
    }
  }
}

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      cycle = false;
      branch = false;
      dfs(i, -1);
      trace(i, cycle, branch);
      if (cycle && !branch) {
        ans++;
      }
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
