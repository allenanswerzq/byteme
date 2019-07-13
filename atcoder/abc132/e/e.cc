/*
 * Name        : e
 * Creat       : Thu Jul 11 20:58:36 CST 2019
 * Accept      : Thu Jul 11 21:10:27 CST 2019
 * Author      : landcold7
 * Motivation  : Action speaks louder more than words
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
  const int inf = (1 << 30);
  vector<vector<int>> dist(n, vector<int>(3, inf));
  deque<pair<int, int>> dq;
  dq.emplace_back(s, 0);
  dist[s][0] = 0;
  while (!dq.empty()) {
    auto u = dq.front().x;
    auto l = dq.front().y;
    dq.pop_front();
    for (auto v : g[u]) {
      int nl = (l + 1) % 3;
      if (dist[v][nl] == inf) {
        dist[v][nl] = dist[u][l] + 1;
        dq.emplace_back(v, nl);
      }
    }
  }
  trace(dist);
  cout << (dist[t][0] == inf ? -1 : dist[t][0] / 3) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
