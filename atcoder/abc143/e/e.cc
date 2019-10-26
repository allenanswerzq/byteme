/* created   : 2019-10-26 10:26:17
 * accepted  : 2019-10-26 12:42:58
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

const int INF = 1e9 + 7;

template <class T>
class graph {
 public:
  struct edge {
    int to;
    int id; // can't see the advantages of adding this field for now.
    T cost;
    friend ostream& operator<<(ostream& os, const edge& e) {
      os << "(" << e.to << ", " << e.cost << ")";
      return os;
    }
  };

  // Adjcent list representation of a graph
  vector<vector<edge>> g;
  int n;
  int id;

  graph(int n_) : n(n_) {
    id = 0;
    g.resize(n);
  }

  void add_direct(int from, int to) {
    g[from].push_back({to, id++, 0});
  }

  void add_direct(int from, int to, const T& cost) {
    g[from].push_back({to, id++, cost});
  }

  void add_undirect(int from, int to, const T& cost) {
    add_direct(from, to, cost);
    add_direct(to, from, cost);
  }

  // single source shortest path
  vector<int> dijkstra(int src) {
    vector<int> dist(n, INF);
    dist[src] = 0;
    typedef pair<int, int> PII;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    while (!q.empty()) {
      auto tp = q.top();
      q.pop();
      int d = tp.first;
      int u = tp.second;
      if (d > dist[u]) {
        continue;
      }
      for (auto e : g[tp.second]) {
        if (dist[u] + e.to < dist[e.to]) {
          dist[e.to] = dist[u] + e.cost;
          q.push(PII{dist[e.to], e.to});
        }
      }
    }
    return dist;
  }

  // single source shortest path on potential nagative weight cycle
  // O(v * e)
  vector<int> bellman_ford(int src, bool* negative_cycle) {
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int u = 0; u < n; u++) {
        for (auto e : g[u]) {
          dist[e.to] = min(dist[e.to], dist[u] + e.cost);
        }
      }
    }
    for (int u = 0; u < n; u++) {
      for (auto e : g[u]) {
        if (dist[u] + e.cost < dist[e.to]) {
          negative_cycle = true;
        }
      }
    }
    return negative_cycle ? vector<int>{} : dist;
  }

  // all pairs shortest path
  vector<vector<int>> floyd_warshall() {
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          dist[i][j] = 0;
        }
        else {
          dist[i][j] = INF;
        }
      }
    }
    for (int u = 0; u < n; u++) {
      for (auto e : g[u]) {
        dist[u][e.to] = e.cost;
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    return dist;
  }
};

void solve() {
  int n, m, l; cin >> n >> m >> l;
  graph<int> g(n);
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--;
    b--;
    g.add_undirect(a, b, c);
  }
  auto d = g.floyd_warshall();
  trace(d);
  graph<int> g2(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (d[i][j] <= l) {
        g2.add_undirect(i, j, 1);
      }
    }
  }
  d = g2.floyd_warshall();
  trace(g2.g, d);
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int s, t; cin >> s >> t;
    s--;
    t--;
    int x = d[s][t];
    cout << (x == INF ? -1 : x - 1) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
