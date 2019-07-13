/* Name        : e
 * Creat       : Sat Jul 13 10:35:51 CST 2019
 * Accept      : Sat Jul 13 12:43:47 CST 2019
 * Author      : landcold7
 * Motto       : Action speaks louder more than words
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
    os << a.x;
    return os;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<vector<mint>> dp(n + 1, vector<mint>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] += dp[i - 1][j - 1] + 1;
      }
    }
  }
  trace(dp);
  cout << (dp[n][m].x + 1) % mod << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
