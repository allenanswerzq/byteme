/* created   : 2020-11-22 16:42:00
 * accepted  : 2020-11-22 19:08:52
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
    trace(u, v);
    gv_.gvAddEdge(u, v);
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
    gv_.gvDrawGraph();
    vector<int> vis(n_);
    vector<int> order;
    for (int i = 0; i < n_; i++) {
      if (!vis[i]) {
        dfs(g_, vis, i, &order, /*scc=*/nullptr);
      }
    }
    vis.assign(n_, 0);
    vector<int> scc(n_);
    scc_index_ = 0;
    for (int i = order.size() - 1; i >= 0; i--) {
      int u = order[i];
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
};

class SATSolver {
 public:
  explicit SATSolver(int n) : n_(n + 1), g_(2 * n_) {}

  // (u | v) && ()
  void AddEdge(int u, int v) {
    // -u ==> v  if u is false, then v must be true
    // -v ==> u
    g_.AddEdge(f(-u), f(v));
    g_.AddEdge(f(-v), f(u));
  }

  // Returns the boolean value for each variable.
  vector<int> Solve() {
    vector<int> scc = g_.DoScc();
    trace(scc);
    for (int i = 1; i < n_; i++) {
      if (scc[f(i)] == scc[f(-i)]) {
        return vector<int>();
      }
    }
    vector<int> ans(n_);
    for (int i = 1; i < n_; i++) {
      ans[i] = scc[f(i)] > scc[f(-i)];
    }
    return ans;
  }

 private:
  int f(int u) {
    assert(u != 0);
    if (u < 0) {
      return 2 * (-u) + 1;
    }
    else {
      return 2 * u;
    }
  }
  int n_;
  SccGraph g_;
};

void solve() {
  int N, M; cin >> N >> M;
  SATSolver g(M);
  for (int i = 0; i < N; i++) {
    char a, b; int u, v;
    cin >> a >> u >> b >> v;
    u *= (a == '+' ? 1 : -1);
    v *= (b == '+' ? 1 : -1);
    trace(u, v);
    g.AddEdge(u, v);
  }
  vector<int> ans = g.Solve();
  if (ans.size()) {
    trace(ans);
    for (int i = 1; i <= M; i++) {
      cout << (ans[i] ? '+' : '-') << (i == M ? '\n' : ' ');
    }
  }
  else {
    cout << "IMPOSSIBLE\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
