/*
 * Creat   : 2019-07-15 16:39:55
 * Accept  : 2019-07-15 17:13:34
 * Author  : landcold7
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
  mint(ll _x = 0)  {
    x = _x % mod;
    if (x < 0) {
      x += mod;
    }
  }

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
    int a = x, b = mod, u = 1, v = 0;
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

void solve() {
  string s;
  cin >> s;
  mint ans = 0;
  mint cnt = 1;
  for (auto c : s) {
    if (c == 'a') {
      cnt *= 2;
    }
    else {
      ans += cnt - 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
