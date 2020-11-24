/* created   : 2020-11-23 09:08:48
 * accepted  : 2020-11-23 21:08:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

class EulerCycle {
 public:
  EulerCycle(int n) : n_(n) {
    g_.resize(n_);
  }

  void AddEdge(int u, int v) {
    int idx = edges_.size();
    g_[u].push_back(idx);
    g_[v].push_back(idx);
    edges_.push_back(make_pair(u, v));
  }

  vector<int> FindEulerCycle() {
    for (int u = 0; u < n_; u++) {
      if (g_[u].size() & 1) {
        return {};
      }
    }
    vector<int> vis(edges_.size());
    vector<int> ans;
    trace(edges_);
    ans.push_back(0);
    Dfs(vis, 0, &ans);
    return ans;
  }

 private:
  void Dfs(vector<int>& vis, int u, vector<int>* ans) {
    while (g_[u].size()) {
      int idx = g_[u].back();
      g_[u].pop_back();
      if (vis[idx]) continue;
      vis[idx] = 1;
      Dfs(vis, edges_[idx].first ^ edges_[idx].second ^ u, ans);
      ans->push_back(u);
    }
  }

  int n_;
  vector<vector<int>> g_;
  vector<pair<int, int>> edges_;
};

void solve() {
  int N, M; cin >> N >> M;
  EulerCycle ep(N);
  Graphviz gv(GraphDrawType::Undirected);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    gv.gvAddEdge(u, v);
    ep.AddEdge(u, v);
  }
  gv.gvDrawGraph();
  vector<int> ans = ep.FindEulerCycle();
  trace(ans);
  if (ans.size() != M + 1) {
    cout << "IMPOSSIBLE\n";
  }
  else {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] + 1 << (i == ans.size() - 1 ? "\n" : " ");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
