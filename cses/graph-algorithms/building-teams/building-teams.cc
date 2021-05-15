/* created   : 2020-11-15 09:29:41
 * accepted  : 2020-11-15 09:40:51
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> color(N, -1);
  std::function<void(int, int, int)> dfs = [&](int u, int p, int c) {
    assert(color[u] == -1);
    color[u] = c;
    for (int v : g[u]) {
      if (v != p) {
        if (color[v] == c) {
          cout << "IMPOSSIBLE\n";
          exit(0);
        }
        if (color[v] == -1) {
          dfs(v, u, c ^ 1);
        }
      }
    }
  };
  for (int i = 0; i < N; i++) {
    if (color[i] == -1) {
      dfs(i, -1, 0);
    }
  }
  for (int i = 0; i < N; i++) {
    cout << color[i] + 1 << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
