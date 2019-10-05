/* created   : 2019-08-22 19:31:24
 * accepted  : 2019-08-23 00:19:19
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

const int N = 1e5;
vector<int> g[N];
int fd[N];
int bk[N];
int pr[N];

void dfs(int u, int par=-1) {
  for (auto v : g[u]) {
    if (v != par) {
      pr[v] = u;
      bk[v]++;
      fd[u]++;
      dfs(v, u);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(pr, -1, sizeof(pr));
  dfs(0);
  trace(pr);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (pr[i] != -1) {
      ans += bk[pr[i]];
    }
  }
  for (int i = 0; i < n; i++) {
    int x = fd[i];
    ans += x * (x - 1) / 2;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
