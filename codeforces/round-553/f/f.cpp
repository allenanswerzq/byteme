//============================================================================
// Name        : f
// Date        : Fri Apr 19 14:39:02 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define fore(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, i, n) { cout << x[i] << (i == n - 1 ? "\n" : " "); }
#define par(x, s, n, v) if(v) pvar(x); fore(i, s, n) prt(x, i, n)
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }
template <typename T> void put(T t) { cout << t << "\n"; }
template <typename T, typename U, typename... Args>
void put(T t, U u, Args... args) { cout << t << " "; put(u, args...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

private:
  using ll = long long;
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

public:
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) {
    if (v < 0) {
      v += MOD;
    }
  }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) {
    return out << int(n);
  }
  friend std::istream& operator >> (std::istream& in, modnum& n) {
    ll v_; in >> v_; n = modnum(v_); return in;
  }
  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }

  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }

  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using md = modnum<int(1e9) + 7>;
using vmd = vector<md>;
using vvmd = vector<vector<md>>;

// TODO: i have no idea...

void mul(vvmd& a, const vvmd& b)  {
  int s = sz(a) - 1;
  vvmd tmp(s + 1, vmd(s + 1));
  for (int i = 0; i <= s; ++i) {
    for (int j = 0; j <= s; ++j) {
      tmp[i][j] = 0;
      for (int k = 0; k <= s; ++k) {
        tmp[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  for (int i = 0; i <= s; ++i) {
    for (int j = 0; j <= s; ++j) {
      a[i][j] = tmp[i][j];
    }
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> cnt(2);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int z = 0;
  for (int i = 0; i < cnt[0]; ++i) {
    if (a[i] == 1) {
      z++;
    }
  }
  int s = min(cnt[0], cnt[1]);
  trace(cnt, s, z);
  vector<vector<md>> tran(s + 1, vector<md>(s + 1));
  for (int i = 0; i <= s; ++i) {
    md p = md(n) * md(n - 1) / md(2);
    md dec = md(i) * md(i) / p;
    md inc = md(cnt[0] - i) * md(cnt[1] - i) / p;
    md same = md(1) - inc - dec;
    if (i > 0) {
      tran[i][i - 1] = dec;
    }
    if (i < 0) {
      tran[i][i + 1] = inc;
    }
    tran[i][i] = same;
  }
  trace(tran);
  vector<vector<md>> dp(s + 1, vector<md>(s + 1));
  for (int i = 0; i <= s; ++i) {
    for (int j = 0; j <= s; ++j) {
      dp[i][j] = md(i == j);
    }
  }
  while (k) {
    if (k & 1) {
      mul(dp, tran);
    }
    mul(tran, tran);
    k >>= 1;
  }
  put(dp[z][0]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
