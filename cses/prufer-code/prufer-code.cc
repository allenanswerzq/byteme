/* created   : 2021-01-09 20:08:22
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

// ref: https://cp-algorithms.com/graph/pruefer_code.html
struct PruferTree {
  vector<vector<int>> g;
  vector<int> deg;
  vector<int> parent;
  int n;

  PruferTree() {}

  explicit PruferTree(int n_) : n(n_) {
    g.resize(n);
    deg.resize(n);
    parent.resize(n, -1);
  }

  void add_edge(int u, int v) {
    assert(0 <= u && u < n);
    assert(0 <= v && v < n);
    g[u].push_back(v);
    g[v].push_back(u);
  }

  void dfs(int u) {
    deg[u] = (int) g[u].size();
    for (int v : g[u]) {
      if (v != parent[u]) {
        parent[v] = u;
        dfs(v);
      }
    }
  }

  vector<int> serialize() {
    dfs(0);
    vector<int> ans(n - 2);
    // All nodes that are smaller than `pos` are either not a leaf or already removed.
    // [.......pos|........]
    int pos = 0;
    while (deg[pos] != 1) pos++;
    int leaf = pos;
    for (int i = 0; i < n - 2; i++) {
      int p = parent[leaf];
      ans[i] = p;
      deg[leaf]--;
      deg[p]--;
      if (deg[p] == 1 && p < pos) {
        leaf = p;
      }
      else {
        while (deg[pos] != 1) pos++;
        leaf = pos;
      }
    }
    return ans;
  }

  void deserialize(const vector<int>& code) {
    n = (int) code.size() + 2;
    g.resize(n);
    deg.resize(n, 1);
    for (int u : code) {
      deg[u]++;
    }
    int pos = 0;
    while (deg[pos] != 1) pos++;
    int leaf = pos;
    trace(deg);
    for (int u : code) {
      add_edge(leaf, u);
      deg[leaf]--;
      deg[u]--;
      if (deg[u] == 1 && u < pos) {
        leaf = u;
      }
      else {
        while (deg[pos] != 1) pos++;
        leaf = pos;
      }
    }
    add_edge(leaf, n - 1);
  }
};

void solve() {
  int N; cin >> N;
  vector<int> A(N - 2);
  for (int& a : A) {
    cin >> a;
    a--;
  }
  PruferTree tree;
  tree.deserialize(A);
  set<pair<int, int>> ans;
  for (int i = 0; i < N; i++) {
    for (int v : tree.g[i]) {
      ans.insert({min(i, v), max(i, v)});
    }
  }
  for (auto& t : ans) {
    cout << t.first + 1 << " " << t.second + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
