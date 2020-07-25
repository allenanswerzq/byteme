/* created   : 2019-10-13 19:34:24
 * accepted  : 2019-10-13 19:46:29
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
int color[N];
int ans;
int n;

void dfs(int u, int pr) {
  trace(pr, u, make_tuple(color, n));
  int col = 0;
  for (auto v : g[u]) {
    if (v != pr) {
      while (col == color[u] || col == color[pr]) {
        col++;
      }
      assert(0 <= col && col < ans);
      color[v] = col++;
      // dfs(v, u);
    }
  }
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, u);
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    ans = max(ans, (int) g[i].size() + 1);
  }
  dfs(0, 0);
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << color[i] + 1 << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
