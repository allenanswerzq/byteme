/* created   : 2022-02-10 23:28:33
 * accepted  : 2022-02-11 00:36:58
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(N);
  map<ar, int> mp;
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    mp[{u, v}] = i;
    mp[{v, u}] = i;
  }
  bool ok = true;
  vector<int> ans(N - 1);
  std::function<void(int,int,int)> dfs = [&](int u, int p, int odd) {
    int c = 0;
    for (int v : g[u]) {
      if (v != p && ok) {
        int i = mp[{u, v}];
        ans[i] = odd ? 2 : 3;
        dfs(v, u, !odd);
        odd = !odd;
        c++;
        if (c > 1 + (p == -1)) {
          ok = false;
          return;
        }
      }
    }
  };
  dfs(0, -1, 1);
  if (!ok) {
    cout << -1 << "\n";
  }
  else {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
