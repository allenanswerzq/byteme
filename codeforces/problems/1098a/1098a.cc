/* created   : 2019-11-03 18:48:42
 * accepted  : 2019-11-03 20:56:16
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

const int N = 1e5 + 7;
vector<int> g[N];
ll sum[N];
ll a[N];
int n;

void dfs(int u, int pr, int h, ll sm) {
  if (h % 2 == 0) {
    int cnt = 0;
    ll mi = 1e9 + 7;
    for (auto v : g[u]) {
      if (v != pr) {
        mi = min(mi, sum[v] - sum[pr]);
        cnt++;
      }
    }
    a[u] = (cnt == 0 ? 0 : mi);
  }
  else {
    a[u] = sum[u] - sm;
  }
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, u, h ^ 1, sm + a[u]);
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[p].push_back(i);
    g[i].push_back(p);
  }
  for (int i = 1; i <= n; i++) {
    cin >> sum[i];
  }
  memset(a, -1, sizeof(a));
  a[1] = sum[1];
  dfs(1, 0, 1, 0);
  trace(mt(a, n));
  trace(mt(sum, n));
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < 0) {
      cout << -1 << '\n';
      return;
    }
    ans += a[i];
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
