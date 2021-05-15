/* created   : 2020-11-20 11:35:37
 * accepted  : 2020-11-20 22:04:46
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, Q; cin >> N >> Q;
  vector<int> pre(N);
  vector<vector<int>> g(N);
  Graphviz gv("g");
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    pre[i] = --x;
    gv.AddEdge(x, i);
    g[x].push_back(i);
  }
  gv.DrawGraph();
  vector<int> root(N, -1);
  vector<int> depth(N);
  vector<int> index(N);
  vector<int> csize(N);
  vector<int> enter(N);
  vector<int> leave(N);
  vector<int> pos(N);
  vector<int> vis(N);
  vector<int> cycle;
  auto is_ancester = [&](int u, int v) {
    return (enter[u] <= enter[v] && leave[v] <= leave[u]);
  };
  int time = 0;
  std::function<void(int)> dfs = [&](int u) {
    time++;
    enter[u] = time;
    trace("enter", u, time);
    for (int v : g[u]) {
      trace(u, v, root[v], root[u], g[u]);
      if (root[v] == -1) {
        root[v] = root[u];
        depth[v] = depth[u] + 1;
        index[v] = index[u];
        csize[v] = csize[u];
        dfs(v);
      }
    }
    trace("leave", u, time);
    leave[u] = time;
  };
  for (int i = 0; i < N; i++) {
    if (root[i] != -1) continue;
    int u = i;
    while (!vis[u]) {
      vis[u] = 1;
      u = pre[u];
    }
    cycle.clear();
    for (int j = u; ;j = pre[j]) {
      if (j == u && cycle.size() >= 1) {
        break;
      }
      index[j] = i;
      root[j] = j;
      pos[j] = cycle.size();
      cycle.push_back(j);
    }
    trace(i, cycle);
    trace(i, index);
    trace(i, pos);
    for (int c : cycle) {
      time = 0;
      csize[c] = cycle.size();
      dfs(c);
      trace(i, c, enter);
      trace(i, c, leave);
    }
  }
  trace(depth, csize, pos);
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    a--, b--;
    trace(a, b);
    int ans = -1;
    if (index[a] == index[b]) {
      if (root[b] == b) {
      // b is a cycle node
        ans = depth[a];
        a = root[a];
        ans += (pos[b] - pos[a] + csize[a]) % csize[a];
      }
      else {
        if (root[a] == root[b] && is_ancester(b, a)) {
          ans = depth[a] - depth[b];
        }
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
