/* created   : 2020-03-21 23:17:26
 * accepted  : 2020-03-22 00:38:28
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

int diamter(vector<vector<int>>& g) {
  int n = g.size();
  // d[i] denotes the farthest distance of the root `i`.
  vector<int> d(n);
  vector<bool> use(n);
  int ans = 0;
  function<void(int)> dfs = [&](int u) {
    use[u] = true;
    for (auto v : g[u]) {
      if (!use[v]) {
        dfs(v);
        ans = max(ans, d[u] + d[v] + 1/*weight(u, v)*/);
        d[u] = max(d[u], d[v] + 1/*weight(u, v)*/);
      }
    }
  };
  dfs(0);
  trace(d);
  return ans;
}

void solve() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n; cin >> n;
  vector<int> hs;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    vector<vector<int>> g(x);
    for (int j = 0; j < 2 * (x - 1); j += 2) {
      int u, v; cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    hs.push_back(diamter(g));
  }
  trace(hs);
  cout << accumulate(all(hs), 0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
