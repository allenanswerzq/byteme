/* created   : 2020-11-28 09:06:02
 * accepted  : 2020-11-28 09:07:40
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <class S, S (*op)(S, S), S (*e)()>
struct Segtree {
 public:
  explicit Segtree(int n) : Segtree(std::vector<S>(n, e())) {}

  explicit Segtree(const std::vector<S>& v) : n_(int(v.size())) {
    log_ = ceil_pow2(n_);
    size_ = 1 << log_;
    d_ = std::vector<S>(2 * size_, e());
    for (int i = 0; i < n_; i++) {
      d_[size_ + i] = v[i];
    }
    for (int i = size_ - 1; i >= 1; i--) {
      update(i);
    }
  }

  int ceil_pow2(int x) {
    int t = 1, c = 0;
    while (t < x) {
      t <<= 1;
      c++;
    }
    return c;
  }

  void set(int p, S x) {
    assert(0 <= p && p < n_);
    p += size_;
    d_[p] = x;
    for (int i = 1; i <= log_; i++) {
      update(p >> i);
    }
  }

  S query(int l, int r) {
    assert(0 <= l && l <= r && r <= n_);
    S sml = e(), smr = e();
    l += size_;
    r += size_;
    while (l < r) {
      if (l & 1) sml = op(sml, d_[l++]);
      if (r & 1) smr = op(d_[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

 private:
  void update(int k) { d_[k] = op(d_[2 * k], d_[2 * k + 1]); }
  int n_, size_, log_;
  std::vector<S> d_;
};

int op(int a, int b) { return a ^ b; }
int e() { return 0; }

void solve() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  Segtree<int, op, e> seg(A);
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    a--, b--;
    cout << seg.query(a, b + 1) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
