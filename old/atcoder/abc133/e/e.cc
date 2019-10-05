/*
 * Name        : e
 * Creat       : Fri Jul 12 11:20:29 CST 2019
 * Accept      : Fri Jul 12 14:16:15 CST 2019
 * Author      : landcold7
 * Motivation  : Action speaks louder more than words
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

const int mod = 1e9 + 7;

struct mint {
  ll x;
  mint(ll _x = 0) : x(_x % mod) {}

  mint& operator+= (const mint a) {
    if ((x += a.x) >= mod) {
      x -= mod;
    }
    return *this;
  }

  mint& operator-=(const mint a) {
    if ((x -= a.x) < 0) {
      x += mod;
    }
    return *this;
  }

  mint& operator*=(const mint a) {
    x = ((x * a.x) % mod);
    return *this;
  }

  mint operator+(const mint a) const {
    mint ret(*this);
    return ret += a;
  }

  mint operator-(const mint a) const {
    mint ret(*this);
    return ret -= a;
  }

  mint operator*(const mint a) const {
    mint ret(*this);
    return ret *= a;
  }

  mint pow(ll t) const {
    if (t == 0) {
      return 1;
    }
    mint ret = pow(t >> 1);
    ret *= ret;
    if (t & 1) {
      ret *= *this;
    }
    return ret;
  }

  // For prime mod
  // TODO(landcold7): generic case
  mint inv() const {
    return pow(mod - 2);
  }

  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }

  mint operator/(const mint a) const {
    mint ret(*this);
    return ret /= a;
  }
  friend ostream& operator<< (ostream& os, mint& a) {
    os << "Mint(" << a.x << ")";
    return os;
  }
};

struct combina {
  vector<mint> fact, fact_inv;
  combina(int n) : fact(n + 1), fact_inv(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i;
    }
    fact_inv[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) {
      fact_inv[i - 1] = fact_inv[i] * i;
    }
  }

  mint nck(int n, int k) {
    return (*this)(n, k);
  }

  mint npk(int n, int k) {
    // nPk = nCk * k!
    mint ret = nck(n, k);
    ret *= fact[k];
    return ret;
  }

  mint operator() (int n, int k) {
    if (k < 0 || n < k) {
      return mint(0);
    }
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
};

const int N = 1e5 + 7;
vector<int> g[N];
combina<mint> comb(N);
int k;
mint ans;

void dfs(int u, int pr = -1) {
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, u);
    }
  }
  int n = (pr == -1 ? k : k - 2);
  int c = (pr == -1 ? sz(g[u]) + 1 : sz(g[u]) - 1);
  ans *= comb.npk(n, c);
}

void solve() {
  int n;
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  trace(comb(5, 3), comb.npk(5, 3));
  ans = 1;
  dfs(0);
  cout << ans.x << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
