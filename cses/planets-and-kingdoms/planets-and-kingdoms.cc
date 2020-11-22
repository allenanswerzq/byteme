/* created   : 2020-11-22 16:29:47
 * accepted  : 2020-11-22 16:35:29
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

class SccGraph {
public:
  explicit SccGraph(int n) : n_(n), scc_index_(0) {
    g_.resize(n_);
    z_.resize(n_);
  }

  void AddEdge(int u, int v) {
    g_[u].push_back(Edge{v});
    z_[v].push_back(Edge{u});
  }

  int SccCount() const { return scc_index_; }

  vector<vector<int>> SccGroup() {
    vector<int> scc = DoScc();
    int scc_count = SccCount();
    assert(scc.size() == n_);
    assert(scc_count >= 1);
    vector<vector<int>> ans(scc_count);
    for (int i = 0; i < n_; i++) {
      ans[scc[i]].push_back(i);
    }
    trace(scc_count, ans);
    for (int i = 0; i < scc_count; i++) {
      assert(ans[i].size() > 0);
    }
    return ans;
  }

  // Returns: scc_id for every node
  std::vector<int> DoScc() {
    vector<int> vis(n_);
    vector<int> order;
    for (int i = 0; i < n_; i++) {
      if (!vis[i]) {
        dfs(g_, vis, i, &order, /*scc=*/nullptr);
      }
    }
    reverse(order.begin(), order.end());
    vis.assign(n_, 0);
    vector<int> scc(n_);
    scc_index_ = 0;
    for (int u : order) {
      if (!vis[u]) {
        dfs(z_, vis, u, /*order=*/nullptr, &scc);
        scc_index_++;
      }
    }
    return scc;
  }

 private:
  // Represents an edge
  struct Edge {
    int to;
  };

  void dfs(vector<vector<Edge>>& g, vector<int>& vis, int u,
           vector<int>* order, vector<int>* scc = nullptr) {
    vis[u] = 1;
    if (scc) {
      trace(u, scc_index_);
      assert(scc->size() == g.size());
      scc->operator[](u) = scc_index_;
    }
    for (auto& e : g[u]) {
      int v = e.to;
      if (vis[v] == 0) {
        dfs(g, vis, v, order, scc);
      }
    }
    if (order) {
      order->push_back(u);
    }
    vis[u] = 2;
  }

  int n_;
  int scc_index_;
  vector<vector<Edge>> g_;
  vector<vector<Edge>> z_;
};

void solve() {
  int N, M; cin >> N >> M;
  SccGraph g(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g.AddEdge(u, v);
  }
  vector<int> scc = g.DoScc();
  cout << g.SccCount() << "\n";
  for (int i = 0; i < scc.size(); i++) {
    cout << scc[i] + 1 << (i == scc.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
