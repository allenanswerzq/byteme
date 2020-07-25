/* created   : 2019-11-17 18:50:58
 * accepted  : 2019-11-17 18:59:33
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

struct Dsu {
  int n;
  int m; // the number of groups after applying join.
  int gid;
  vector<int> e;
  vector<int> root_hash;
  vector<int> gid_hash;

  Dsu(int n_) : n(n_) {
    m = n;
    gid = 0;
    e.resize(n, -1);
    root_hash.resize(n, -1);
    gid_hash.resize(n, -1);
  }

  int size(int x) {
    return -e[find(x)];
  }

  int find_rec(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }

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
    if (e[a] > e[b]) {
      swap(a, b);
    }
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

void solve() {
  int n; cin >> n;
  string a, b; cin >> a >> b;
  Dsu dsu(26);
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      dsu.join(a[i] - 'a', b[i] - 'a');
    }
  }
  auto g = dsu.groups();
  vector<pair<int, int>> ans;
  for (int i = 0; i < dsu.m; i++) {
    int root = dsu.get_groot(i);
    for (auto v : g[i]) {
      if (v != root) {
        ans.emplace_back(v, root);
      }
    }
  }
  trace(ans);
  cout << ans.size() << '\n';
  for (auto t : ans) {
    cout << char(t.x + 'a') << ' ' << char(t.y + 'a') << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
