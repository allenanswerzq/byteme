/* created   : 2020-06-25 14:50:16
 * accepted  : 2020-06-25 16:30:18
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

struct Node {
  int cost;
  int city;
  int fuel;
  bool operator<(const Node& rhs) const {
    return cost > rhs.cost;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<int> price(n);
  vector<vector<pair<int, int>>> g(n);
  for (auto& x : price) {
    cin >> x;
  }
  for (int i = 0; i < m; i++) {
    int u, v, d; cin >> u >> v >> d;
    g[u].push_back({v, d});
    g[v].push_back({u, d});
  }
  int q; cin >> q;
  const int INF = 1e9 + 7;
  const int C = 120;
  while (q--) {
    int cap, start, end; cin >> cap >> start >> end;
    vector<vector<int>> dis(n, vector<int>(C, INF));
    vector<vector<int>> use(n, vector<int>(C));
    priority_queue<Node> qu;
    qu.push({0, start, 0});
    dis[start][0] = 0;
    bool ok = false;
    while (qu.size()) {
      auto tp = qu.top(); qu.pop();
      int cost = tp.cost;
      int city = tp.city;
      int fuel = tp.fuel;
      // trace(cost, city, fuel);
      if (city == end) {
        cout << cost << "\n";
        ok = true;
        break;
      }
      if (use[city][fuel]) continue;
      use[city][fuel] = true;
      if (fuel + 1 <= cap) {
        if (dis[city][fuel + 1] > dis[city][fuel] + price[city]) {
          dis[city][fuel + 1] = dis[city][fuel] + price[city];
          qu.push({dis[city][fuel + 1], city, fuel + 1});
        }
      }
      for (auto [v, w] : g[city]) {
        if (fuel >= w) {
          dis[v][fuel - w] = cost;
          qu.push({cost, v, fuel - w});
        }
      }
    }
    if (!ok) {
      cout << "impossible\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
