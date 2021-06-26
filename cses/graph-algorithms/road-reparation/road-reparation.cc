/* created   : 2020-11-21 10:56:52
 * accepted  : 2021-06-26 16:39:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

struct Dsu {
  vector<int> e;
  int n;

  Dsu(int n_) : n(n_) {
    e.resize(n, -1);
  }

  int find(int u) {
    return e[u] < 0 ? u : e[u] = find(e[u]);
  }

  bool same(int a, int b) {
    return find(a) == find(b);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return;
    }
    if (-e[a] < -e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    n--;
  }
};

void solve_kruskal() {
  // Kruskal's algorithm
  int N, M; cin >> N >> M;
  vector<array<ll, 3>> edge(M);
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    edge[i] = {c, a, b};
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> vis(N);
  std::function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int v : g[u]) {
      if (!vis[v]) {
        dfs(v);
      }
    }
  };
  dfs(0);
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  sort(all(edge));
  Dsu dsu(N);
  ll ans = 0;
  int cnt = 0;
  for (int i = 0; i < M && cnt < N; i++) {
    ll c = edge[i][0], u = edge[i][1], v = edge[i][2];
    if (!dsu.same(u, v)) {
      cnt++;
      dsu.unite(u, v);
      ans += c;
    }
  }
  cout << ans << "\n";
}

void solve() {
  // Prim's algorithm
  int N, M; cin >> N >> M;
  vector<vector<array<int, 2>>> g(N);
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  vector<int> vis(N);
  std::function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (auto t : g[u]) {
      int v = t[0];
      if (!vis[v]) {
        dfs(v);
      }
    }
  };
  dfs(0);
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  ll ans = 0;
  int cnt = 0;
  priority_queue<array<ll, 2>, vector<array<ll, 2>>> qu;
  for (auto t : g[0]) {
    qu.push({-t[1], t[0]});
  }
  int u = 0;
  vector<int> seen(N);
  seen[u] = 1;
  while (qu.size() && cnt < N) {
    auto top = qu.top();
    qu.pop();
    ll c = -top[0], v = top[1];
    // Skip cycle
    if (seen[v]) continue;
    seen[v] = 1;
    cnt++;
    ans += c;
    for (auto t : g[v]) {
      if (!seen[t[0]]) {
        qu.push({-t[1], t[0]});
      }
    }
    u = v;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
