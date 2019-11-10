/* created   : 2019-11-09 21:04:30
 * accepted  : 2019-11-10 09:52:03
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
typedef pair<ll, int> PII;

struct edge {
  int to;
  int cost;
};

const int N = 1e5 + 7;
const ll INF = 1e18;
vector<edge> g[N];
int n;
int m;

template <class T>
vector<T> dijkstra(int src) {
  vector<T> dist(n, INF);
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
    for (edge e : g[tp.second]) {
      if (dist[u] + e.cost < dist[e.to]) {
        dist[e.to] = dist[u] + e.cost;
        q.push(PII{dist[e.to], e.to});
      }
    }
  }
  return dist;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    g[i + 1].push_back(edge{i, 0});
  }
  for (int i = 0; i < m; i++) {
    int u, v, c; cin >> u >> v >> c;
    u--, v--;
    g[u].push_back(edge{v, c});
  }
  vector<ll> dist = dijkstra<ll>(0);
  cout << (dist[n - 1] == INF ? -1 : dist[n - 1]) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
