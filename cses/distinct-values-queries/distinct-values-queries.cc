/* created   : 2020-11-29 09:37:15
 * accepted  : 2020-11-29 15:58:04
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <class T>
class Bit {
 public:
  Bit(int n) : n_(n) { t_.resize(n_ + 1); }

  void add(int x, int d) {
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

  T query(int l, int r) { return query(r) - query(l - 1); }

 private:
  int lowbit(int x) { return x & -x; }
  int n_;
  vector<T> t_;
};

void solve() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<vector<array<int, 2>>> query(N);
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    a--, b--;
    query[b].push_back({a, i});
  }
  Bit<int> bit(N);
  map<int, int> mp;
  vector<int> ans(Q);
  for (int i = 0; i < N; i++) {
    bit.add(i, 1);
    if (mp.count(A[i])) {
      // -1 + 1 == 0
      bit.add(mp[A[i]], -1);
    }
    mp[A[i]] = i;
    for (array<int, 2>& t : query[i]) {
      ans[t[1]] = bit.query(t[0], i);
    }
  }
  for (int i = 0; i < Q; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
