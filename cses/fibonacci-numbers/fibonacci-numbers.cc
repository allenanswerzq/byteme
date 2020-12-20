/* created   : 2020-12-20 22:02:20
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <int mod_>
struct Modnum {
  static constexpr int mod = mod_;
  static_assert(mod_ > 0, "mod must be positive");

 private:
  using ll = long long;
  int v;

  static int inv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(inv(m, a)) * ll(m) / a);
  }

 public:
  Modnum() : v(0) {}

  Modnum(ll v_) : v(int(v_ % mod)) {
    if (v < 0) {
      v += mod;
    }
  }

  explicit operator int() const { return v; }

  friend std::ostream& operator<<(std::ostream& out, const Modnum& n) {
    return out << int(n);
  }

  friend std::istream& operator>>(std::istream& in, Modnum& n) {
    ll x;
    in >> x;
    n = Modnum(x);
    return in;
  }

  friend bool operator==(const Modnum& a, const Modnum& b) { return a.v == b.v; }
  friend bool operator!=(const Modnum& a, const Modnum& b) { return a.v != b.v; }

  Modnum inv() const {
    Modnum res;
    res.v = inv(v, mod);
    return res;
  }

  Modnum neg() const {
    Modnum res;
    res.v = v ? mod - v : 0;
    return res;
  }

  Modnum operator-() const { return neg(); }

  Modnum operator+() const { return Modnum(*this); }

  Modnum& operator++() {
    v++;
    if (v == mod) v = 0;
    return *this;
  }

  Modnum& operator--() {
    if (v == 0) v = mod;
    v--;
    return *this;
  }

  Modnum& operator+=(const Modnum& o) {
    v += o.v;
    if (v >= mod) v -= mod;
    return *this;
  }

  Modnum& operator-=(const Modnum& o) {
    v -= o.v;
    if (v < 0) v += mod;
    return *this;
  }

  Modnum& operator*=(const Modnum& o) {
    v = int(ll(v) * ll(o.v) % mod);
    return *this;
  }

  Modnum& operator/=(const Modnum& o) { return *this *= o.inv(); }

  friend Modnum operator++(Modnum& a, int) {
    Modnum r = a;
    ++a;
    return r;
  }
  friend Modnum operator--(Modnum& a, int) {
    Modnum r = a;
    --a;
    return r;
  }
  friend Modnum operator+(const Modnum& a, const Modnum& b) { return Modnum(a) += b; }
  friend Modnum operator-(const Modnum& a, const Modnum& b) { return Modnum(a) -= b; }
  friend Modnum operator*(const Modnum& a, const Modnum& b) { return Modnum(a) *= b; }
  friend Modnum operator/(const Modnum& a, const Modnum& b) { return Modnum(a) /= b; }
};


template <class T>
struct Matrix {
  vector<vector<T>> v_;
  int n_;
  int m_;

  Matrix(int n, int m) : n_(n), m_(m) {
    v_.resize(n_, vector<T>(m_));
  }

  Matrix(const Matrix& o) {
    *this = o;
  }

  vector<T>& operator[](int r) {
    assert(0 <= r && r < n_);
    return v_[r];
  }

  void operator=(const Matrix& o) {
    v_ = o.v_;
    n_ = o.n_;
    m_ = o.m_;
  }

  void debug() {
    trace(v_);
  }

  void operator*=(const Matrix& o) {
    assert(m_ == o.n_);
    Matrix ans(n_, o.m_);
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < o.m_; j++) {
        T cur = 0;
        for (int k = 0; k < m_; k++) {
          cur += v_[i][k] * o.v_[k][j];
        }
        ans.v_[i][j] = cur;
      }
    }
    *this = ans;
  }

  Matrix operator^(ll t) {
    assert(t >= 0);
    assert(n_ == m_);
    Matrix ans(n_, m_);
    for (int i = 0; i < n_; i++) {
      ans.v_[i][i] = 1;
    }
    Matrix a(*this);
    while (t) {
      if (t & 1) ans *= a;
      a *= a;
      t >>= 1;
    }
    return ans;
  }

  friend Matrix operator*(const Matrix& a, const Matrix& b) { return Matrix(a) *= b; }
};

const int mod = 1e9 + 7;
using num = Modnum<mod>;

void solve() {
  // fn   [1, 1] [fn-1]
  // fn-1 [1, 0] [fn-2]

  // f2 [1,1] f1
  // f1 [1,0] f0

  // f3 [1,1] f2 == A2 f1
  // f2 [1,0] f1 == A2 f0

  ll N; cin >> N;
  if (N == 0) {
    cout << 0 << "\n";
    return;
  }
  Matrix<num> ans(2, 2);
  Matrix<num> z(2, 1);
  z[0] = {1};
  z[1] = {0};
  ans[0] = {1, 1};
  ans[1] = {1, 0};
  ans = ans ^ (N - 1);
  ans *= z;
  cout << ans[0][0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
