/* created   : 2021-07-26 09:00:37
 * accepted  : 2021-07-26 09:36:48
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

struct Dsu {
  int n;
  int m;
  int gid;
  vector<int> e;
  vector<int> root_hash;
  vector<int> gid_hash;

  Dsu() = default;

  Dsu(int n_) { resize(n_); }

  void resize(int n_) {
    n = n_;
    m = n;
    gid = 0;
    e.resize(n, -1);
    root_hash.resize(n, -1);
    gid_hash.resize(n, -1);
  }

  int size(int x) { return -e[find(x)]; }

  int find_rec(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }

  int find(int u) {
    int root = u;
    while (e[root] >= 0) {
      root = e[root];
    }
    while (u != root) {
      int t = e[u];
      e[u] = root;
      u = t;
    }
    return root;
  }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return false;
    }
    if (-e[a] < -e[b]) {
      swap(a, b);
    }
    // the tree with fewer nodes been added.
    e[a] += e[b];
    e[b] = a;
    m--;
    return true;
  }

  // Given a gid, finds the root of that group
  int get_groot(int ix) {
    assert(0 <= ix && ix < n);
    assert(root_hash[ix] != -1);
    return root_hash[ix];
  }

  // Given a root, finds the gid.
  int get_gid(int root) {
    assert(0 <= root && root < n);
    if (gid_hash[root] == -1) {
      gid_hash[root] = gid;
      root_hash[gid] = root;
      gid++;
    }
    return gid_hash[root];
  }

  vector<vector<int>> groups() {
    vector<vector<int>> ret(m);
    // Note: zero index based.
    for (int i = 0; i < n; i++) {
      int root = find(i);
      ret[get_gid(root)].push_back(i);
    }
    return ret;
  }
};

void dfs(int u, vector<vector<int>>& g, Dsu& dsu, vector<int>& visit) {
  trace(u);
  visit[u] = 1;
  for (int v : g[u]) {
    if (!visit[v]) {
      dsu.join(u, v);
      dfs(v, g, dsu, visit);
    }
  }
}

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N; i++) {
    int to; cin >> to;
    to--;
    g[i].push_back(to);
  }
  trace(g);
  Dsu dsu(N);
  vector<int> visit(N);
  for (int i = 0; i < N; i++) {
    if (!visit[i]) {
      dfs(i, g, dsu, visit);
    }
  }
  vector<int> ans(N);
  auto grps = dsu.groups();
  trace(grps);
  for (auto& grp : grps) {
    for (int v : grp) {
      ans[v] = grp.size();
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
