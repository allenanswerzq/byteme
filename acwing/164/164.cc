/* created   : 2020-06-21 09:49:56
 * accepted  : 2020-06-21 10:26:45
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 3e4 + 7;
vector<int> g[N];

void solve() {
  int n, m; cin >> n >> m;
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    deg[v]++;
  }
  vector<int> order;
  deque<int> qu;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      qu.push_back(i);
    }
  }
  while (qu.size()) {
    int u = qu.front(); qu.pop_front();
    order.push_back(u);
    for (auto v : g[u]) {
      if (--deg[v] == 0) {
        qu.push_back(v);
      }
    }
  }
  trace(order);
  assert(order.size() == n);
  vector<bitset<N>> f(n);
  for (int i = n - 1; i >= 0; i--) {
    int u = order[i];
    f[u][u] = 1;
    for (auto v : g[u]) {
      f[u] |= f[v];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << f[i].count() << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
