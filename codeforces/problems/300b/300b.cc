/* created   : 2019-10-27 14:13:11
 * accepted  : 2019-10-27 16:12:35
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
    for (int i = 0; i < n; i++) {
      int root = find(i);
      // trace(i, root, ret);
      ret[get_idx(root)].push_back(i);
    }
    return ret;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  dsu du(n);
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a--, b--;
    du.join(a, b);
  }
  for (int i = 0; i < n; i++) {
    int root = du.find(i);
    if (du.size(root) > 3) {
      cout << -1 << '\n';
      return;
    }
  }
  vector<vector<int>> gp = du.groups();
  vector<vector<int>> three;
  vector<vector<int>> two;
  vector<vector<int>> one;
  for (auto t : gp) {
    if (t.size() == 3) {
      three.push_back(t);
    }
    else if (t.size() == 2) {
      two.push_back(t);
    }
    else {
      one.push_back(t);
    }
  }
  if (two.size() > one.size()) {
    cout << -1 << '\n'; return;
  }
  for (auto& t : two) {
    t.push_back(one.back()[0]);
    one.pop_back();
  }
  vector<int> ans;
  for (auto t : three) {
    for (int i = 0; i < 3; i++) {
      ans.push_back(t[i]);
    }
  }
  for (auto t : two) {
    for (int i = 0; i < 3; i++) {
      ans.push_back(t[i]);
    }
  }
  for (auto t : one) {
    ans.push_back(t[0]);
  }
  trace(ans, three, two, one, gp);
  for (int i = 0; i < ans.size(); i += 3) {
    cout << ans[i] + 1 << ' ' << ans[i + 1] + 1 << ' ' << ans[i + 2] + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
