/* created   : 2021-10-17 10:38:39
 * accepted  : 2021-10-17 11:49:33
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N);
  string ss;
  getline(cin, ss);
  {
    getline(cin, ss);
    istringstream in(ss);
    set<ar> st;
    int u, v;
    char ch;
    while (in >> ch >> u >> ch >> v >> ch) {
      u--, v--;
      assert(u != v);
      if (st.count({u, v}) || st.count({v, u})) {
        cout << "No" << "\n";
        exit(0);
      }
      g[u].push_back(v);
      g[v].push_back(u);
      st.insert({u, v});
      st.insert({v, u});
    }
  }
  trace(N, M, ss, g);
  int cnt = 0;
  vector<int> vis(N);
  std::function<void(int,int)> dfs = [&](int u, int p) {
    vis[u] = 1;
    cnt++;
    for (int v : g[u]) {
      if (vis[v]) {
        if (v == p) continue;
        cout << "No" << "\n";
        exit(0);
      }
      dfs(v, u);
    }
  };
  dfs(0, -1);
  int ok = (cnt == N);
  cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
