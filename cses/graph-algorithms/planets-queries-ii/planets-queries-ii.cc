/* created   : 2020-11-20 11:35:37
 * accepted  : 2021-06-26 09:38:25
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

int N;
int Q;
vector<vector<int>> g;
vector<bool> visit;
vector<int> pre;
vector<int> root;
vector<int> cidx;
vector<int> csize;
vector<int> depth;
vector<int> enter;
vector<int> leave;
int counter;

void dfs(int u) {
  visit[u] = true;
  counter++;
  enter[u] = counter;
  for (int v : g[u]) {
    if (!visit[v]) {
      csize[v] = csize[u];
      depth[v] = depth[u] + 1;
      root[v] = root[u];
      cidx[v] = cidx[u];
      dfs(v);
    }
  }
  leave[u] = counter;
}

bool is_ancestor(int a, int b) {
  return enter[a] <= enter[b] && leave[b] <= leave[a];
}

void solve() {
  cin >> N >> Q;
  g.resize(N);
  pre.resize(N, -1);
  visit.resize(N);
  cidx.resize(N);
  csize.resize(N);
  root.resize(N);
  depth.resize(N);
  enter.resize(N);
  leave.resize(N);
  Graphviz gv(GraphDrawType::Directed);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    x--;
    // reverse the edge direction (i --> x) to (x --> i)
    pre[i] = x;
    g[x].push_back(i);
    gv.gvAddEdge(x, i);
  }
  gv.gvDrawGraph();
  vector<int> seen(N);
  vector<int> cpos(N);
  for (int i = 0; i < N; i++) {
    if (visit[i]) continue;
    // NOTE: each connected graph must have a cycle in it.
    int u = i;
    for (; !seen[u]; u = pre[u]) {
      seen[u] = true;
    }
    // Now, `u` is a node on the cycle
    vector<int> cycle;
    for (int j = u; ;j = pre[j]) {
      if (j == u && cycle.size() > 1) break;
      cycle.push_back(j);
      visit[j] = true;
    }
    // Cycle here is at the reversed direction, so changed it back
    reverse(all(cycle));
    trace(u, cycle, root);
    for (int t = 0; t < (int) cycle.size(); t++) {
      int c = cycle[t];
      cidx[c] = u;
      csize[c] = (int) cycle.size();
      cpos[c] = t;
      root[c] = c;
      counter = 0;
      dfs(c);
    }
  }
  trace(cidx);
  trace(root);
  trace(depth);
  trace(csize);
  trace(cpos);
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    a--, b--;
    // NOTE: we reversed edeg at the beginning, so here we need
    // to start from b then go to a
    // b --> a
    trace(b, a);
    int ans = -1;
    if (cidx[a] == cidx[b]) {
      // Both belong to the same connected graph
      if (root[b] == b) {
        // b is a cycle node, then it's definitely can reach to a
        // b --> root[a] --> a
        ans = depth[a];
        a = root[a];
        ans += (cpos[a] - cpos[b] + csize[a]) % csize[a];
      }
      else if (root[a] == root[b] && is_ancestor(b, a)) {
        ans = depth[a] - depth[b];
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
