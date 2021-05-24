/* created   : 2021-05-22 21:41:34
 * accepted  : 2021-05-24 09:06:49
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

int N, Q;
vector<vector<int>> g;
vector<int> parent;
map<ar, ar> mp;

void dfs(int u, int p = -1) {
  assert(u < N);
  parent[u] = p;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}

void solve() {
  cin >> N >> Q;
  g.clear();
  parent.clear();
  mp.clear();
  g.resize(N);
  parent.resize(N);
  for (int i = 0; i < N - 1; i++) {
    ll u, v, l, a; cin >> u >> v >> l >> a;
    u--, v--;
    // trace(u, v, l, a, N, Q);
    assert(u < N);
    assert(0 <= v && v < N);
    g[u].push_back(v);
    g[v].push_back(u);
    mp[{u, v}] = {l, a};
    mp[{v, u}] = {l, a};
  }
  dfs(0);
  for (int i = 0; i < Q; i++) {
    if (i > 0) {
      cout << " ";
    }
    int u, w; cin >> u >> w;
    u--;
    ll gd = -1;
    for (int p = parent[u]; p != -1; ) {
      auto l = mp[{u, p}];
      if (w >= l[0]) {
        gd = (gd == -1 ? l[1] : __gcd(gd, l[1]));
      }
      u = p;
      p = parent[u];
    }
    cout << max(gd, 0ll);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
