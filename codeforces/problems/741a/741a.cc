/* created   : 2019-11-12 08:15:34
 * accepted  : 2019-11-12 08:52:18
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

const int N = 120;
vector<int> g[N];
bool use[N];
int cnt;
int n;

void dfs(int u) {
  if (use[u]) {
    return;
  }
  cnt++;
  use[u] = true;
  for (int v : g[u]) {
    dfs(v);
  }
}

int lcm(int a, int b) {
  return a * b / __gcd(a, b);
}

void solve() {
  cin >> n;
  vector<int> deg(n);
  for (int u = 0; u < n; u++) {
    int v; cin >> v;
    v--;
    deg[v]++;
    g[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      cout << -1 << '\n';
      return;
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      cnt = 0;
      dfs(i);
      ans = lcm(ans, (cnt % 2 ? cnt : cnt / 2));
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
