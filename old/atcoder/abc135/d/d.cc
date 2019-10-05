/* created   : 2019-08-09 10:28:07
 * accepted  : 2019-08-09 19:59:15
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int mod = 1e9 + 7;

struct mint {
  ll x;
  mint(ll _x = 0)  {
    x = _x % mod;
    if (x < 0) {
      x += mod;
    }
  }

  mint& operator+=(const mint a) {
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

  mint operator++(int) {
    mint ret(*this);
    *this += 1;
    return ret;
  }

  mint operator--(int) {
    mint ret(*this);
    *this -= 1;
    return ret;
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
    mint ret = 1;
    mint p = *this;
    while (t) {
      if (t & 1) {
        ret *= p;
      }
      p *= p;
      t >>= 1;
    }
    return ret;
  }

  mint inv() const {
    int a = x;
    int b = mod;
    int u = 1;
    int v = 0;
    while (b != 0) {
      int t = a / b;
      a -= t * b;
      u -= t * v;
      swap(a, b);
      swap(u, v);
    }
    assert(b == 1);
    if (u < 0) {
      u += mod;
    }
    return u;
  }

  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }

  mint operator/(const mint a) const {
    mint ret(*this);
    return ret /= a;
  }

  friend ostream& operator<< (ostream& os, mint& a) {
    return os << a.x;
  }
};

const int N = 1e5 + 7;
mint dp[N][17];

void solve() {
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> p(n);
  p[0] = 1;
  for (int i = 1; i < n; i++) {
    p[i] = (p[i - 1] * 10) % 13;
  }
  reverse(s.begin(), s.end());
  for (int i = 0; i <= 9; i++) {
    if (s[0] == '?' || s[0] - '0' == i) {
      dp[0][i] = 1;
    }
  }
  trace(make_pair(dp[0], 13), p, s);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 13; j++) {
      for (int k = 0; k <= 9; k++) {
        if (s[i] == '?' || s[i] - '0' == k) {
          int cur = (j + k * p[i]) % 13;
          dp[i][cur] += dp[i - 1][j];
        }
      }
    }
  }
  cout << dp[n - 1][5] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
