/* created   : 2019-08-29 10:37:21
 * accepted  : 2019-08-29 10:56:25
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
vector<int> sub[N];
vector<int> g[N];
int ans[N];
int inc[N];

void dfs(int u, int pr, int val) {
  ans[u] += val + inc[u];
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, u, val + inc[u]);
    }
  }
}

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < q; i++) {
    int p, x; cin >> p >> x;
    inc[--p] += x;
  }
  dfs(0, -1, 0);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
