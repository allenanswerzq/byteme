/* created   : 2020-12-18 22:25:07
 * accepted  : 2020-12-18 23:35:41
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <int mod_>
struct Modnum {
  static constexpr int mod = mod_;
  static_assert(mod_ > 0, "mod must be positive");

  typedef Modnum MD;

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

  friend std::ostream& operator<<(std::ostream& out, const MD& n) {
    return out << int(n);
  }

  friend std::istream& operator>>(std::istream& in, MD& n) {
    ll x;
    in >> x;
    n = MD(x);
    return in;
  }

  friend bool operator==(const MD& a, const MD& b) { return a.v == b.v; }
  friend bool operator!=(const MD& a, const MD& b) { return a.v != b.v; }

  MD inv() const {
    MD res;
    res.v = inv(v, mod);
    return res;
  }

  MD neg() const {
    MD res;
    res.v = v ? mod - v : 0;
    return res;
  }

  MD operator-() const { return neg(); }

  MD operator+() const { return MD(*this); }

  MD& operator++() {
    v++;
    if (v == mod) v = 0;
    return *this;
  }

  MD& operator--() {
    if (v == 0) v = mod;
    v--;
    return *this;
  }

  MD& operator+=(const MD& o) {
    v += o.v;
    if (v >= mod) v -= mod;
    return *this;
  }

  MD& operator-=(const MD& o) {
    v -= o.v;
    if (v < 0) v += mod;
    return *this;
  }

  MD& operator*=(const MD& o) {
    v = int(ll(v) * ll(o.v) % mod);
    return *this;
  }

  MD& operator/=(const MD& o) { return *this *= o.inv(); }

  friend MD operator++(MD& a, int) {
    MD r = a;
    ++a;
    return r;
  }
  friend MD operator--(MD& a, int) {
    MD r = a;
    --a;
    return r;
  }
  friend MD operator+(const MD& a, const MD& b) { return MD(a) += b; }
  friend MD operator-(const MD& a, const MD& b) { return MD(a) -= b; }
  friend MD operator*(const MD& a, const MD& b) { return MD(a) *= b; }
  friend MD operator/(const MD& a, const MD& b) { return MD(a) /= b; }
};

using num = Modnum<(int)1e9+7>;

num compute(num x) {
  return x * (x + 1) / 2;
}

void solve() {
  int n; cin >> n;
  num ans = 0;
  for (ll i = 1; i <= n;) {
    // [i ... r]
    ll r = n / (n / i);
    ll x = n / i;
    ans += (compute(r) - compute(i - 1)) * x;
    i = r + 1;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
