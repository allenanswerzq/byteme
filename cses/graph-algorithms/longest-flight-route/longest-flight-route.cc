/* created   : 2020-11-19 16:42:43
 * accepted  : 2021-06-19 07:26:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int INF = 1e9;
int N, M;
vector<vector<int>> g;
vector<int> dist;
vector<int> nxt;
vector<int> visit;

void dfs(int u) {
  visit[u] = true;
  for (int v : g[u]) {
    if (!visit[v]) {
      dfs(v);
    }
    if (dist[v] != -INF && dist[u] < dist[v] + 1) {
      dist[u] = dist[v] + 1;
      nxt[u] = v;
    }
  }
}

void solve() {
  cin >> N >> M;
  g.resize(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  nxt.resize(N, -1);
  dist.resize(N, -INF);
  visit.resize(N);
  dist[N - 1] = 0;
  dfs(0);
  if (dist[0] == -INF) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  vector<int> ans;
  for (int u = 0; u != -1; u = nxt[u]) {
    ans.push_back(u);
  }
  cout << dist[0] + 1 << "\n";
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
