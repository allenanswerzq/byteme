/* created   : 2019-10-07 22:09:39
 * accepted  : 2019-10-07 23:55:15
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

const int N = 1200;
vector<int> g[N];
int use[N];
vector<vector<int>> ans;
vector<int> cycle;
int n, m;

void dfs(int u) {
  if (use[u]) {
    ans.push_back(cycle);
    return;
  }
  use[u] = 1;
  cycle.push_back(u);
  for (auto v : g[u]) {
    dfs(v);
  }
  cycle.pop_back();
  use[u] = 0;
}
// TODO(zq7): TLE or RE
void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    dfs(i);
  }
  if (ans.empty()) {
    cout << -1 << '\n';
    return;
  }
  int mi = (1 << 30);
  int idx = -1;
  for (int i = 0; i < (int) ans.size(); i++) {
    if ((int) ans[i].size() < mi) {
      mi = (int) ans[i].size();
      idx = i;
    }
  }
  assert(idx != -1);
  cout << ans[idx].size() << '\n';
  for (auto x : ans[idx]) {
    cout << x + 1 << '\n';
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
