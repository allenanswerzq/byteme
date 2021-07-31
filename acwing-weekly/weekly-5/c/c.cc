/* created   : 2021-07-31 10:21:49
 * accepted  : 2021-07-31 17:45:19
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

inline ll get(const ar& x, const ar& y) {
  return abs(x[0] - y[0]) + abs(x[1] - y[1]);
}

void solve() {
  int N; cin >> N;
  vector<ar> city(N + 1);
  for (int i = 1; i <= N; i++) {
    int x, y; cin >> x >> y;
    city[i] = {x, y};
  }
  trace(city);
  // Use 0 as a center node
  const ll INF = 1e18 + 7;
  vector<ll> dist(N + 1, INF);
  vector<int> pre(N + 1, -1);
  for (int i = 1; i <= N; i++) {
    int c; cin >> c;
    dist[i] = c;
    pre[i] = 0;
  }
  vector<int> coff(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> coff[i];
  }
  // Prime algorithm (N^2)
  vector<int> seen(N + 1);
  seen[0] = 1;
  dist[0] = 0;
  ll cost = 0;
  vector<int> station;
  vector<ar> edge;
  for (int i = 1; i <= N; i++) {
    int u = -1;
    for (int j = 1; j <= N; j++) {
      if (!seen[j] && (u == -1 || dist[j] < dist[u])) {
        u = j;
      }
    }
    assert(u != -1);
    seen[u] = 1;
    cost += dist[u];
    if (pre[u] == 0) {
      station.push_back(u);
    }
    else {
      edge.push_back({pre[u], u});
    }
    // Extend to all edges that u connects to.
    for (int j = 1; j <= N; j++) {
      if (seen[j]) continue;
      ll d = get(city[u], city[j]) * (coff[u] + coff[j]);
      if (d < dist[j]) {
        // dist[j] stands for mininum weight that j has through all connecting edges.
        dist[j] = d;
        pre[j] = u;
      }
    }
  }
  cout << cost << "\n";
  cout << station.size() << "\n";
  for (int i = 0; i < station.size(); i++) {
    cout << station[i] << (i == station.size() - 1 ? '\n' : ' ');
  }
  cout << edge.size() << "\n";
  for (auto e : edge) {
    cout << e[0] << " " << e[1] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
