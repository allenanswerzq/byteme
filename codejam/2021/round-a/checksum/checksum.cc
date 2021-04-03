/* created   : 2021-04-03 08:15:17
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void dfs(const vector<vector<ar>>& g, vector<int>& vis, int u) {
  vis[u] = 1;
  for (auto v : g[u]) {
    if (!vis[v[0]]) {
      dfs(g, vis, v[0]);
    }
  }
}

void solve() {
  int N; cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  ll tot_cost = 0;
  vector<vector<ar>> g(N + N);
  vector<vector<int>> B(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> B[i][j];
      if (A[i][j] == -1) {
        tot_cost += B[i][j];
        g[i].push_back({N + j, B[i][j]});
        g[N + j].push_back({i, B[i][j]});
      }
    }
  }
  vector<int> R(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> R[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  trace(A, B);
  trace(g, tot_cost);
  vector<int> vis(N + N);
  ll max_spanning_cost = 0;
  for (int i = 0; i < N + N; i++) {
    if (!vis[i]) {
      dfs(g, vis, i);
      // For every tree in a forest
      // Prim's algorithm
      priority_queue<ar, vector<ar>> qu;
      vector<int> seen(N + N);
      seen[i] = 1;
      for (auto t : g[i]) {
        qu.push({/*weight*/ t[1], /*node*/ t[0]});
      }
      while (qu.size()) {
        trace(qu);
        auto t = qu.top(); qu.pop();
        int w = t[0], u = t[1];
        if (seen[u]) continue;
        trace(w, u, max_spanning_cost);
        max_spanning_cost += w;
        seen[u] = 1;
        for (auto e : g[u]) {
          if (!seen[e[0]]) {
            qu.push({e[1], e[0]});
          }
        }
      }
    }
  }
  trace(tot_cost, max_spanning_cost);
  assert(tot_cost >= max_spanning_cost);
  cout << tot_cost - max_spanning_cost << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
