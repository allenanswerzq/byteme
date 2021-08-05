/* created   : 2021-08-04 06:34:09
 * accepted  : 2021-08-04 08:23:55
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

ll dfs(int u, vector<vector<ar>> & g, vector<int>& W, vector<int>& visit, ll& ans) {
  visit[u] = 1;
  ll d1 = 0, d2 = 0;
  for (auto e : g[u]) {
    int v = e[0], c = e[1];
    if (visit[v]) continue;
    ll d = dfs(v, g, W, visit, ans);
    if (d < c) continue;
    d -= c;
    if (d >= d1) {
      d2 = d1;
      d1 = d;
    }
    else if (d > d2) {
      d2 = d;
    }
  }
  ans = max(ans, d1 + d2 + W[u]);
  return d1 + W[u];
}

void solve() {
  int N; cin >> N;
  vector<int> W(N);
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }
  vector<vector<ar>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v, c; cin >> u >> v >> c;
    u--, v--;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  vector<int> visit(N);
  ll ans = 0;
  dfs(0, g, W, visit, ans);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
