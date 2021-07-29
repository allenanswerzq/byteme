/* created   : 2021-07-29 07:37:20
 * accepted  : 2021-07-29 22:12:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N);
  vector<ar> cand;
  vector<int> deg(N);
  for (int i = 0; i < M; i++) {
    int t, x, y; cin >> t >> x >> y;
    x--, y--;
    if (t == 0) {
      cand.push_back({x, y});
    }
    else {
      g[x].push_back(y);
      deg[y]++;
    }
  }
  deque<int> qu;
  for (int i = 0; i < N; i++) {
    if (deg[i] == 0) {
      qu.push_back(i);
    }
  }
  map<int, int> order;
  int cnt = 0;
  while (qu.size()) {
    int u = qu.front(); qu.pop_front();
    assert(!order.count(u));
    order[u] = cnt++;
    for (int v : g[u]) {
      if (--deg[v] == 0) {
        qu.push_back(v);
      }
    }
  }
  if (order.size() != N) {
    cout << "NO\n";
    return;
  }
  else {
    cout << "YES\n";
    for (int i = 0; i < N; i++) {
      for (int j : g[i]) {
        cout << i + 1 << " " << j + 1 << "\n";
      }
    }
    for (auto & e : cand) {
      if (order[e[0]] < order[e[1]]) {
        // e[0] -- > e[1]
      }
      else {
        swap(e[0], e[1]);
      }
      cout << e[0] + 1 << " " << e[1] + 1 << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
