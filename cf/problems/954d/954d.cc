/* created   : 2019-11-21 08:53:50
 * accepted  : 2019-11-22 11:12:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

template <class T>
struct Graph {
  struct edge {
    int to;
    T cost;
    friend ostream& operator<<(ostream& os, const edge& e) {
      os << "(" << e.to << ", " << e.cost << ")";
      return os;
    }
  };

  // Adjcent list representation of a Graph
  vector<vector<edge>> g;
  int n;

  Graph(int n_) : n(n_) {
    g.resize(n);
  }

  void add_direct(int from, int to, const T& cost = 1) {
    g[from].push_back(edge{to, cost});
  }

  void add_undirect(int from, int to, const T& cost = 1) {
    add_direct(from, to, cost);
    add_direct(to, from, cost);
  }

  vector<edge>& operator[](int u) {
    return g[u];
  }
};

template <class T, T INF>
vector<T> dijkstra(const Graph<T>& ga, int src) {
  vector<T> dist(ga.n, INF);
  typedef pair<T, int> PII;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  dist[src] = 0;
  q.push({0, src});
  while (!q.empty()) {
    auto tp = q.top();
    q.pop();
    T d = tp.first;
    int u = tp.second;
    if (d > dist[u]) {
    // A very important line of code here
      continue;
    }
    for (auto e : ga.g[tp.second]) {
      if (dist[u] + e.cost < dist[e.to]) {
        dist[e.to] = dist[u] + e.cost;
        q.push(PII{dist[e.to], e.to});
      }
    }
  }
  return dist;
}

void solve() {
  int n, m, s, t; cin >> n >> m >> s >> t;
  s--, t--;
  Graph<int> g(n);
  vector<vector<int>> use(n, vector<int>(n));
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g.add_undirect(u, v);
    use[u][v] = use[v][u] = 1;
  }
  const int INF = 1 << 30;
  vector<int> ds = dijkstra<int, INF>(g, s);
  vector<int> dt = dijkstra<int, INF>(g, t);
  assert(ds[t] == dt[s]);
  int mi = ds[t];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (use[i][j] || i == j) {
        continue;
      }
      int cur = min(ds[i] + dt[j], ds[j] + dt[i]) + 1;
      if (cur >= mi) {
        trace(i, j, mi, ds, dt);
        ans++;
      }
    }
  }
  cout << ans / 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
