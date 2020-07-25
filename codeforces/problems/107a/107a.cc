/* created   : 2019-10-27 22:16:40
 * accepted  : 2019-10-29 00:49:40
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

struct node {
  int tank;
  int tap;
  int water;
};

const int N = 1200;
vector<pair<int, int>> g[N];
bool use[N];
bool cycle;
int water;
int tap;
int n;
int m;

void dfs(int u) {
  if (use[u]) {
    cycle = true;
    return;
  }
  use[u] = 1;
  tap = u;
  for (auto v : g[u]) {
    water = min(water, v.y);
    dfs(v.x);
  }
}

void solve() {
  cin >> n >> m;
  if (m == 0) {
    cout << 0 << '\n';
    return;
  }
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    u--, v--;
    g[u].emplace_back(v, w);
    deg[v]++;
  }
  vector<node> ans;
  int tank;
  for (int i = 0; i < n; i++) {
    if (!deg[i]) {
      tank = i;
      tap = -1;
      water = 1 << 30;
      cycle = false;
      dfs(i);
      if (!cycle && tap != tank) {
        ans.push_back({tank, tap, water});
      }
    }
  }
  sort(ans.begin(), ans.end(), [](const node& a, const node& b) {
    return a.tank < b.tank;
  });
  cout << ans.size() << '\n';
  for (auto t : ans) {
    cout << t.tank + 1 << ' ' << t.tap + 1 << ' ' << t.water << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
