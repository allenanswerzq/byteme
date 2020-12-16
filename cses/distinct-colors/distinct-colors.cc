/* created   : 2020-12-16 22:31:41
 * accepted  : 2020-12-16 23:04:53
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;


template <class T>
class Bit {
 public:
  Bit(int n) : n_(n) { t_.resize(n_ + 1); }

  // Add to interval [0...x].
  void add(int x, T d) {
    for (++x; x <= n_; x += lowbit(x)) {
      t_[x] += d;
    }
  }

  // Query sum of interval [0...x].
  T query(int x) {
    T ans = 0;
    for (++x; x > 0; x -= lowbit(x)) {
      ans += t_[x];
    }
    return ans;
  }

  // Query sum of interval [l...r].
  T query(int l, int r) { return query(r) - query(l - 1); }

 private:
  int lowbit(int x) { return x & -x; }
  int n_;
  vector<T> t_;
};

void solve() {
  int N; cin >> N;
  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> enter(N);
  map<int, int> leave;
  vector<int> order;
  std::function<void(int, int)> dfs = [&](int u, int p) {
    enter[u] = order.size();
    order.push_back(C[u]);
    for (int v : g[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
    leave[order.size()] = u;
    order.push_back(C[u]);
  };
  dfs(0, -1);
  trace(enter, leave, order);
  map<int, int> mp;
  Bit<int> bit(order.size());
  vector<int> ans(N);
  for (int i = 0; i < order.size(); i++) {
    bit.add(i, 1);
    if (mp.count(order[i])) {
      bit.add(mp[order[i]], -1);
    }
    mp[order[i]] = i;
    if (leave.count(i)) {
      int u = leave[i];
      ans[u] = bit.query(enter[u], i);
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
