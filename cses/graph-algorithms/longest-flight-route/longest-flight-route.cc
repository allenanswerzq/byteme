/* created   : 2020-11-19 16:42:43
 * accepted  : 2022-04-08 22:24:49
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
    if (visit[v]) continue;
    dfs(v);
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

// TLE: longest path
void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  vector<int> dist(N, 0);
  vector<int> pre(N, -1);
  dist[0] = 0;
  priority_queue<ar, vector<ar>> qu;
  qu.push({0, 0});
  while (qu.size()) {
    auto tp = qu.top(); qu.pop();
    int d = tp[0], u = tp[1];
    if (dist[u] < d) continue;
    for (int v : g[u]) {
      // time complexity: mlogn
      // total for loop is m each time min heap cost logn
      if (dist[v] < dist[u] + 1) {
        dist[v] = dist[u] + 1;
        qu.push({dist[v], v});
        pre[v] = u;
      }
    }
  }
  // trace(dist);
  if (dist[N - 1] == 0) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  vector<int> ans;
  for (int u = N - 1; u != -1; u = pre[u]) {
    ans.push_back(u);
  }
  reverse(all(ans));
  cout << dist[N - 1] + 1 << "\n";
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
