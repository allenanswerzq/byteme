/* created   : 2020-01-04 18:40:07
 * accepted  : 2020-01-04 19:10:39
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

void amax(int& a, int b) { a = max(a, b); }

const int N = 6200;
vector<int> g[N];
int not_choose[N];
int choose[N];
int deg[N];
int a[N];
int n;

void dfs(int u) {
  if (g[u].size() == 0) {
    choose[u] = a[u];
    not_choose[u] = 0;
    return;
  }
  int sa = 0;
  int sb = 0;
  for (auto v : g[u]) {
    dfs(v);
    sa += choose[v];
    sb += not_choose[v];
  }
  amax(choose[u], sb + a[u]);
  amax(not_choose[u], sa);
  amax(not_choose[u], sb);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    int l, k; cin >> l >> k;
    g[k].push_back(l);
    deg[l]++;
  }
  int root = -1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      cnt++;
      root = i;
    }
  }
  assert(cnt == 1);
  assert(root != -1);
  trace(cnt, root);
  dfs(root);
  cout << max(choose[root], not_choose[root]) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
