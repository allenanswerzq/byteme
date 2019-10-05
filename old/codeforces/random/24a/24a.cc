/* created   : 2019-08-16 20:48:01
 * accepted  : 2019-08-17 09:46:55
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
vector<pair<int, int>> fd[N];
vector<pair<int, int>> bk[N];
int root;
int ans;

void dfs(int u, int pr, int cost) {
  if (u == root) {
    ans = min(ans, cost);
    return;
  }
  // If i can walk following forwrad direction.
  for (auto v : fd[u]) {
    if (v.x != pr) {
      dfs(v.x, u, cost);
      return;
    }
  }
  for (auto v : bk[u]) {
    if (v.x != pr) {
      dfs(v.x, u, cost + v.y);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    fd[u].emplace_back(v, c);
    bk[v].emplace_back(u, c);
  }
  root = -1;
  for (int i = 0; i < n; i++) {
    if ((int) fd[i].size() == 2) {
      root = i;
      break;
    }
  }
  if (root == -1) {
    cout << 0 << '\n';
    return;
  }
  assert(root != -1);
  ans = 1 << 30;
  int cost = 0;
  dfs(fd[root][0].x, root, cost);
  dfs(fd[root][1].x, root, cost);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
