/* created   : 2020-11-15 09:16:00
 * accepted  : 2020-11-15 09:24:58
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  const int INF = 1e5 + 7;
  vector<int> pre(N, INF);
  deque<int> qu;
  qu.push_back(0);
  pre[0] = -1;
  bool ok = false;
  while (qu.size()) {
    int u = qu.front(); qu.pop_front();
    if (u == N - 1) {
      ok = true;
      break;
    }
    for (int v : g[u]) {
      if (pre[v] == INF) {
        pre[v] = u;
        qu.push_back(v);
      }
    }
  }
  if (!ok) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  vector<int> ans;
  int u = N - 1;
  while (1) {
    ans.push_back(u);
    if (pre[u] == -1) break;
    u = pre[u];
  }
  reverse(all(ans));
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
