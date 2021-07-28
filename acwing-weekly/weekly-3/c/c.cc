/* created   : 2021-07-28 07:09:06
 * accepted  : 2021-07-28 22:53:34
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

template <class T>
class Bit {
 public:
  Bit(int n) : n_(n) { t_.resize(n_ + 1); }

  void add(int x, T d) {
    for (++x; x <= n_; x += lowbit(x)) {
      t_[x] = max(t_[x], d);
    }
  }

  // Query maxinum value of interval [0...x].
  T query(int x) {
    T ans = 0;
    for (++x; x > 0; x -= lowbit(x)) {
      ans = max(t_[x], ans);
    }
    return ans;
  }

 private:
  int lowbit(int x) { return x & -x; }
  int n_;
  vector<T> t_;
};

template <bool ONE = false>
struct Discreter {
  unordered_map<int, int> raw_dis_;
  vector<int> sorted_;

  Discreter(vector<int> &val) {
    sorted_ = val;
    sort(all(sorted_));
    sorted_.erase(unique(all(sorted_)), sorted_.end());
    for (int &x : val) {
      int p = lower_bound(all(sorted_), x) - sorted_.begin() + ONE;
      raw_dis_[x] = p;
    }
  }

  // The maxinum value after discreting
  int max() { return sorted_.size(); }

  // Given a raw value, returns the discreted value.
  int get(int r) { return raw_dis_[r]; }

  // Given a discreted value, returns the raw value.
  int raw(int d) { return sorted_[d - ONE]; }
};

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int & a : A) {
    cin >> a;
  }
  Discreter<> dis(A);
  const int Z = 1e5;
  Bit<ll> bit(Z);
  // f[i] = max(f[j]) + A[i] (for all j < i, A[j] < A[i]);
  vector<ll> f(N);
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll v = bit.query(dis.get(A[i]) - 1);
    f[i] = v + A[i];
    ans = max(ans, f[i]);
    bit.add(dis.get(A[i]), f[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
