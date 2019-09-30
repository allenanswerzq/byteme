/* created   : 2019-09-05 10:43:54
 * accepted  : 2019-09-05 15:07:45
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  int node = 0;
  vector<vector<int>> g(n * n);
  vector<int> deg(n * n);
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= n; i++) {
    int pr = -1;
    for (int j = 1; j <= n - 1; j++) {
      int v; cin >> v;
      int u = i;
      if (u > v) {
        swap(u, v);
      }
      if (!mp.count({u, v})) {
        mp[{u, v}] = node++;
      }
      if (j == 1) {
        pr = mp[{u, v}];
      }
      else {
        int cr = mp[{u, v}];
        g[pr].push_back(cr);
        deg[cr]++;
        pr = cr;
      }
    }
  }
  trace(deg, g);
  deque<int> dq;
  int cnt = 0;
  for (int i = 0; i < node; i++) {
    if (deg[i] == 0) {
      dq.push_back(i);
      cnt++;
    }
  }
  int ans = 0;
  while (!dq.empty()) {
    ans++;
    int sd = dq.size();
    for (int i = 0; i < sd; i++) {
      int u = dq.front(); dq.pop_front();
      for (auto v : g[u]) {
        if (--deg[v] == 0) {
          dq.push_back(v);
          cnt++;
        }
      }
    }
  }
  cout << (cnt == n * (n - 1) / 2 ? ans : -1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
