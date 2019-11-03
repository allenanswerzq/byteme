/* created   : 2019-11-03 16:23:26
 * accepted  : 2019-11-03 18:20:42
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

const int N = 1e5 + 7;
vector<int> g[N];
int color[N];
int n;

bool dfs(int u, int pr, int col) {
  bool ret = 1;
  for (auto v : g[u]) {
    if (v != pr) {
      ret &= (col == color[v]);
      ret &= dfs(v, u, col);
    }
  }
  return ret;
}

bool check(int u) {
  bool ret = 1;
  for (auto v : g[u]) {
    ret &= dfs(v, u, color[v]);
  }
  return ret;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int c; cin >> c;
    color[i] = c;
  }
  pair<int, int> e = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (auto v : g[i]) {
      if (color[i] != color[v]) {
        e = {i, v};
        break;
      }
    }
  }
  if (e.x == -1 && e.y == -1) {
    cout << "YES" << '\n';
    cout << 1 << '\n';
    return;
  }
  trace(e);
  if (check(e.x)) {
    cout << "YES" << '\n';
    cout << e.x + 1 << '\n';
  }
  else if (check(e.y)) {
    cout << "YES" << '\n';
    cout << e.y + 1 << '\n';
  }
  else {
    cout << "NO" << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
