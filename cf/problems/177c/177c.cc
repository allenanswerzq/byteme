/* created   : 2019-11-02 19:53:50
 * accepted  : 2019-11-02 20:11:42
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

struct dsu {
  int n;
  int m; // the number of groups after applying join.
  int idx;
  vector<int> e;
  vector<int> root_hash;
  vector<int> idx_hash;

  dsu(int n_) : n(n_) {
    m = n;
    idx = 0;
    e.resize(n, -1);
    root_hash.resize(n, -1);
    idx_hash.resize(n, -1);
  }

  int size(int x) {
    return -e[find(x)];
  }

  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
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

  int get_root(int ix) {
    assert(0 <= ix && ix < n);
    assert(root_hash[ix] != -1);
    return root_hash[ix];
  }

  int get_idx(int root) {
    assert(0 <= root && root < n);
    if (idx_hash[root] == -1) {
      idx_hash[root] = idx;
      root_hash[idx] = root;
      idx++;
    }
    return idx_hash[root];
  }

  vector<vector<int>> groups() {
    vector<vector<int>> ret(m);
    // Note: 0-based.
    for (int i = 0; i < n; i++) {
      int root = find(i);
      ret[get_idx(root)].push_back(i);
    }
    return ret;
  }
};

void solve() {
  int n; cin >> n;
  int m; cin >> m;
  dsu ds(n);
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    ds.join(x, y);
  }
  (void) ds.groups();
  vector<int> g(n);
  for (int i = 0; i < n; i++) {
    g[i] = ds.find(i);
  }
  vector<int> invite(ds.m, 1);
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    int rx = ds.find(x);
    int ry = ds.find(y);
    if (rx == ry) {
      invite[ds.get_idx(rx)] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i < ds.m; i++) {
    if (invite[i]) {
      ans = max(ans, ds.size(ds.get_root(i)));
    }
  }
  trace(invite);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
