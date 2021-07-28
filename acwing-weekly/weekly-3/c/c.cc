/* created   : 2021-07-28 07:09:06
 * accepted  : 2021-07-28 08:48:35
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

struct Discreter {
  vector<int> e;
  unordered_map<int, int> t;
  int mx = 0;
  bool one = true;

  Discreter(const vector<int>& v) {
    e = v;
    sort(all(e));
    e.erase(unique(all(e)), e.end());
    for (int x : v) {
      int p = lower_bound(all(e), x) - e.begin() + one;
      mx = max(mx, p);
      t[x] = p;
    }
  }

  int size() { return mx; }

  // Given a raw value, returns the discreted value.
  int get_dis(int x) { return t[x]; }

  // Given a discreted value, return the raw value.
  int get_raw(int x) { return e[x - one]; }
};

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int & a : A) {
    cin >> a;
  }
  Discreter dis(A);
  const int Z = 1e5;
  Bit<ll> bit(Z);
  // f[i] = max(f[j]) + A[i] (for all j < i, A[j] < A[i]);
  vector<ll> f(N);
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll v = bit.query(dis.get_dis(A[i]) - 1);
    f[i] = v + A[i];
    ans = max(ans, f[i]);
    bit.add(dis.get_dis(A[i]), f[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
