/* created   : 2020-11-22 20:55:46
 * accepted  : 2020-11-22 22:05:41
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
    gv_.gvAddEdge(u, v);
    g_[u].push_back(Edge{v});
    z_[v].push_back(Edge{u});
  }

  int SccCount() const { return scc_index_; }

  vector<vector<int>> ComponentGroup() {
    vector<int> scc = DoScc();
    int scc_count = SccCount();
    assert((int)scc.size() == n_);
    assert(scc_count >= 1);
    vector<vector<int>> ans(scc_count);
    for (int i = 0; i < n_; i++) {
      ans[scc[i]].push_back(i);
    }
    for (int i = 0; i < scc_count; i++) {
      assert(ans[i].size() > 0);
    }
    return ans;
  }

  // Returns: scc_id for every node
  std::vector<int> DoScc() {
    if (scc_.size()) {
      return scc_;
    }
    gv_.gvDrawGraph();
    vector<int> vis(n_);
    vector<int> order;
    for (int i = 0; i < n_; i++) {
      if (!vis[i]) {
        dfs(g_, vis, i, &order, /*scc=*/nullptr);
      }
    }
    vis.assign(n_, 0);
    scc_.resize(n_);
    scc_index_ = 0;
    for (int i = order.size() - 1; i >= 0; i--) {
      int u = order[i];
      if (!vis[u]) {
        dfs(z_, vis, u, /*order=*/nullptr, &scc_);
        scc_index_++;
      }
    }
    return scc_;
  }

  vector<vector<int>> ComponentGraph() {
    vector<int> scc = DoScc();
    int cnt = SccCount();
    vector<set<int>> tmp(cnt);
    for (int u = 0; u < n_; u++) {
      for (Edge& e : g_[u]) {
        int v = e.to;
        if (scc[u] != scc[v]) {
          tmp[scc[u]].insert(scc[v]);
        }
      }
    }
    vector<vector<int>> ans(cnt);
    Graphviz cg("cg");
    for (int i = 0; i < cnt; i++) {
      for (int u : tmp[i]) {
        cg.gvAddEdge(i, u);
        ans[i].push_back(u);
      }
    }
    cg.gvDrawGraph();
    return ans;
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
  Graphviz gv_;
  vector<vector<Edge>> g_;
  vector<vector<Edge>> z_;
  vector<int> scc_;
};

void solve() {
  int N, M; cin >> N >> M;
  vector<int> coin(N);
  for (int i = 0; i < N; i++) {
    cin >> coin[i];
  }
  SccGraph g(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g.AddEdge(u, v);
  }
  vector<vector<int>> group = g.ComponentGroup();
  int cnt = g.SccCount();
  vector<vector<int>> cg = g.ComponentGraph();
  vector<ll> coins(cnt);
  for (int i = 0; i < cnt; i++) {
    ll s = 0;
    for (int u : group[i]) {
      s += coin[u];
    }
    coins[i] = s;
  }
  trace(g.DoScc(), coins, cg, group);
  vector<int> vis(cnt);
  vector<ll> f(all(coins));
  std::function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int v : cg[u]) {
      assert(vis[v] != 1);
      if (vis[v] == 0) {
        dfs(v);
      }
      trace(u, v, f[u], f[v], f[v] + coins[u]);
      f[u] = max(f[u], f[v] + coins[u]);
    }
    vis[u] = 2;
  };
  for (int i = 0; i < cnt; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  trace(f);
  cout << *max_element(all(f)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
