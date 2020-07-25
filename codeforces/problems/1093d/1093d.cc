/* created   : 2019-11-19 08:05:13
 * accepted  : 2019-11-19 11:19:30
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

template <int mod_>
struct Modnum {
  static constexpr int mod = mod_;
  static_assert(mod_ > 0, "mod must be positive");

 private:
  using ll = long long;
  using MD = Modnum;
  int v;

  static int inv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll( inv(m, a) ) * ll(m) / a);
  }

 public:
  Modnum() : v(0) {}

  Modnum(ll v_) : v(int(v_ % mod)) {
    if (v < 0) {
      v += mod;
    }
  }

  explicit operator int() const { return v; }

  friend std::ostream& operator << (std::ostream& out, const MD& n) {
    return out << int(n);
  }

  friend std::istream& operator >> (std::istream& in, MD& n) {
    ll x; in >> x;
    n = MD(x);
    return in;
  }

  friend bool operator == (const MD& a, const MD& b) { return a.v == b.v; }
  friend bool operator != (const MD& a, const MD& b) { return a.v != b.v; }

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

  MD operator- () const {
    return neg();
  }

  MD operator+ () const {
    return MD(*this);
  }

  MD& operator ++ () {
    v++;
    if (v == mod) v = 0;
    return *this;
  }

  MD& operator -- () {
    if (v == 0) v = mod;
    v--;
    return *this;
  }

  MD& operator += (const MD& o) {
    v += o.v;
    if (v >= mod) v -= mod;
    return *this;
  }

  MD& operator -= (const MD& o) {
    v -= o.v;
    if (v < 0) v += mod;
    return *this;
  }

  MD& operator *= (const MD& o) {
    v = int(ll(v) * ll(o.v) % mod);
    return *this;
  }

  MD& operator /= (const MD& o) {
    return *this *= o.inv();
  }

  friend MD operator ++ (MD& a, int) { MD r = a; ++a; return r; }
  friend MD operator -- (MD& a, int) { MD r = a; --a; return r; }
  friend MD operator + (const MD& a, const MD& b) { return MD(a) += b; }
  friend MD operator - (const MD& a, const MD& b) { return MD(a) -= b; }
  friend MD operator * (const MD& a, const MD& b) { return MD(a) *= b; }
  friend MD operator / (const MD& a, const MD& b) { return MD(a) /= b; }
};

using Mod = Modnum<998244353>;
const int N = 3e5 + 7;
vector<int> g[N];
int use[N];
bool cycle;
int n;
int m;

Mod dfs(int u, bool odd, int pr = -1) {
  // trace("dfs", pr, u);
  if (use[u]) {
    if (use[u] == use[pr]) {
      cycle = true;
    }
    return 1;
  }
  Mod cnt = 1;
  if (odd == true) {
    cnt *= 2;
  }
  use[u] = (odd ? 1 : 2);
  for (auto v : g[u]) {
    if (v != pr) {
      cnt *= dfs(v, odd ^ 1, u);
    }
  }
  return cnt;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  // trace(n, m, mt(g, n));
  vector<Mod> a(n);
  // memset(use, 0, sizeof(use));
  fill(use, use + n, 0);
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      cycle = false;
      Mod x = dfs(i, true);
      if (cycle) {
        cout << 0 << '\n';
        return;
      }
      a[i] += x;
    }
  }
  // trace(ans);
  // memset(use, 0, sizeof(use));
  fill(use, use + n, 0);
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      Mod x = dfs(i, false);
      a[i] += x;
    }
  }
  Mod ans = 1;
  for (int i = 0; i < n; i++) {
    if (int(a[i]) > 0) {
      ans *= a[i];
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
