/* created   : 2019-09-07 16:49:22
 * accepted  : 2019-09-07 21:37:04
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

const int N = 1e5 + 7;
vector<int> g[N];
int from[N];
int to[N];
int color[N];

void dfs(int u) {
  for (auto v : g[u]) {
    if (color[v] == -1) {
      color[v] = (color[u] ^ 1);
      dfs(v);
    }
  }
}

void print(vector<int>& v) {
  int n = v.size();
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << v[i] + 1;
  }
  cout << '\n';
}

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    from[i] = u;
    to[i] = v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(color, -1, sizeof(color));
  for (int i = 0; i < n; i++) {
    if (color[i] == -1 && !g[i].empty()) {
      color[i] = 0;
      dfs(i);
    }
  }
  trace(make_pair(color, n));
  for (int i = 0; i < m; i++) {
    if (color[from[i]] == color[to[i]]) {
      cout << -1 << '\n';
      return;
    }
  }
  vector<int> seta, setb;
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      seta.push_back(i);
    }
    else if (color[i] == 1) {
      setb.push_back(i);
    }
  }
  print(seta);
  print(setb);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
