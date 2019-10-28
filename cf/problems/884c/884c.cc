/* created   : 2019-10-27 16:28:10
 * accepted  : 2019-10-27 16:44:00
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
  dsu du(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    x--;
    du.join(i, x);
  }
  vector<vector<int>> gp = du.groups();
  vector<int> a;
  for (auto t : gp) {
    a.push_back(t.size());
  }
  sort(a.begin(), a.end(), greater<int>());
  trace(a);
  int mx = a[0];
  if (a.size() >= 2) {
    mx += a[1];
  }
  ll ans = (ll) mx * mx;
  for (int i = 2; i < a.size(); i++) {
    ans += (ll) a[i] * a[i];
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
