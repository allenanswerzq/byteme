/* created   : 2019-11-18 08:24:57
 * accepted  : 2019-11-18 08:58:47
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
class Graph {
  struct edge {
    int to;
    T cost;
    friend ostream& operator<<(ostream& os, const edge& e) {
      os << "(" << e.to << ", " << e.cost << ")";
      return os;
    }
  };
 public:
  // Adjcent list representation of a graph
  vector<vector<edge>> g;
  int n;

  Graph(int n_) : n(n_) {
    g.resize(n);
  }

  void add_direct(int from, int to) {
    g[from].push_back(edge{to, 0});
  }

  void add_direct(int from, int to, const T& cost) {
    g[from].push_back(edge{to, cost});
  }

  void add_undirect(int from, int to, const T& cost) {
    add_direct(from, to, cost);
    add_direct(to, from, cost);
  }

  Graph& operator[](int u) {
    return g[u];
  }
};

template <class T, T INF>
vector<T> dijkstra(const Graph<T>& ga, int src) {
  int n = ga.n;
  vector<T> dist(n, INF);
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
    // Very important line of code here
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
  int n; cin >> n;
  Graph<ll> g(n);
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    v--;
    if (v != i) {
      g.add_direct(i, v, 1);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    g.add_undirect(i, i + 1, 1);
  }
  const ll INF = 1e8;
  vector<ll> dist = dijkstra<ll, INF>(g, 0);
  for (int i = 0; i < n; i++) {
    cout << (dist[i] != INF ? dist[i] : i) << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
