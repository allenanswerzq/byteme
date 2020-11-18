/* created   : 2020-11-18 15:01:52
 * accepted  : 2020-11-18 18:20:56
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<array<int, 2>>> g(N);
  // Graphviz gv("g");
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    // gv.AddEdge(a, b, c);
    a--, b--;
    g[a].push_back({b, c});
  }
  // gv.DrawGraph();
  const ll INF = 1e18;
  vector<ll> dist(N, INF);
  vector<int> pre(N);
  dist[0] = 0;
  pre[0] = -1;
  for (int i = 0; i < N - 1; i++) {
    for (int u = 0; u < N; u++) {
      for (auto& t : g[u]) {
        int v = t[0], c = t[1];
        if (dist[u] + c < dist[v]) {
          dist[v] = dist[u] + c;
          pre[v] = u;
        }
      }
    }
  }
  for (int u = 0; u < N; u++) {
    for (auto& t : g[u]) {
      int v = t[0], c = t[1];
      if (dist[u] + c < dist[v]) {
        // NOTE: we process the node in the order from 0 to N - 1, after the
        // fisrt N - 1 iteration, the previous pointer `pre` must point to the
        // node inside cycle for every cycle node.
        //
        // NOTE: the edge (u-->v) may not a cycle edge, thus we need to find a
        // node that is actually on the cycle, just following the previous path,
        // eventually we will walk into the cycle.
        //
        // e.g.
        //        4
        //     /     \
        // -->  cycle 12--> 2 --> 6
        //     \ ... /
        //
        // When processing node 12, it may lead to a reduce for node 2, thus in
        // the `next` iteration, when processing node 2, there will be a
        // reduce for node 6, but edge (2 --> 6) is not a cycle edge.
        vector<int> visit(N);
        while (!visit[u]) {
          visit[u] = 1;
          u = pre[u];
          assert(u != -1);
        }
        // Now, the u definitely is a node on the cycle.
        trace(u);
        cout << "YES\n";
        vector<int> ans;
        ans.push_back(u);
        int j = pre[u];
        while (j != u) {
          ans.push_back(j);
          j = pre[j];
        }
        ans.push_back(u);
        reverse(all(ans));
        for (int i = 0; i < ans.size(); i++) {
          cout << ans[i] + 1 << (i == ans.size() - 1 ? '\n' : ' ');
        }
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
