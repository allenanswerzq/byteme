/* created   : 2021-07-27 07:19:41
 * accepted  : 2021-07-27 08:36:51
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void dfs(int u, vector<vector<ar>>& g, vector<int>& visit, vector<int>& ans, int K) {
  if (ans.size() >= K) return;
  visit[u] = 1;
  for (auto e : g[u]) {
    int v = e[0];
    int edge_id = e[1];
    if (!visit[v]) {
      if (ans.size() < K) {
        ans.push_back(edge_id);
        dfs(v, g, visit, ans, K);
      }
    }
  }
}

void solve() {
  int N, M, K; cin >> N >> M >> K;
  vector<vector<array<int, 3>>> g(N);
  for (int i = 0; i < M; i++) {
    int x, y, w; cin >> x >> y >> w;
    x--, y--;
    g[x].push_back({{y, w, i}});
    g[y].push_back({{x, w, i}});
  }
  trace(g);
  const ll INF = 1e18;
  vector<ll> dist(N, INF);
  vector<ar> pre(N);
  priority_queue<ar, vector<ar>> qu;
  qu.push({0, 0});
  dist[0] = 0;
  while (qu.size()) {
    auto tp = qu.top(); qu.pop();
    ll d = -tp[0];
    int u = static_cast<int>(tp[1]);
    if (dist[u] < d) continue;
    assert(dist[u] == d);
    for (auto e : g[u]) {
      int v = e[0], w = e[1];
      // trace(u, v, w);
      if (dist[u] + w < dist[v]) {
        pre[v] = {{u, e[2]}};
        dist[v] = dist[u] + w;
        qu.push({-dist[v], v});
      }
    }
  }
  trace(dist);
  trace(pre, K);
  vector<vector<ar>> tree(N);
  for (int i = 0; i < N; i++) {
    int p = pre[i][0];
    tree[p].push_back({i, pre[i][1]});
  }
  vector<int> visit(N);
  vector<int> ans;
  dfs(0, tree, visit, ans, K);
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      cout << ' ';
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
