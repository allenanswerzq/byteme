/* created   : 2019-10-19 20:19:12
 * accepted  : 2019-10-19 21:19:41
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

const int N = 1e5 + 7;
vector<int> g[N];
vector<int> ans;
int init[N];
int goal[N];
int n;

void dfs(int u, int pr, int x, int y) {
  trace("dfs", pr, u);
  init[u] ^= x;
  if (init[u] != goal[u]) {
    ans.push_back(u);
    x ^= 1;
  }
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, u, y, x);
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    cin >> init[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> goal[i];
  }
  dfs(0, -1, 0, 0);
  int sz = ans.size();
  cout << sz << '\n';
  for (int i = 0; i < sz; i++) {
    cout << ans[i] + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
