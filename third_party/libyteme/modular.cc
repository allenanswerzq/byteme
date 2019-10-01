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

const int md = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += md;
  }
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) {
    a += md;
  }
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a;
    u -= t * v;
    swap(a, b);
    swap(u, v);
  }
  assert(b == 1);
  if (u < 0) {
    u += md;
  }
  return u;
}
