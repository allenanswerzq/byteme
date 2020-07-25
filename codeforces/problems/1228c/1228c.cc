/* created   : 2020-04-14 23:06:10
 * accepted  : 2020-04-15 00:36:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

namespace numbers_t {
template <class T>
vector<pair<T, int>> factors(T n) {
  vector<pair<T, int>> ret;
  for (T i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      ret.push_back({i, cnt});
    }
  }
  if (n > 1) {
    ret.push_back({n, 1});
  }
  return ret;
}

ll phi(ll x) {
  for (auto& a : factors(x)) {
    x -= x / a.first;
  }
  return x;
}

template <class T>
void tour(vector<pair<T, int>>& v, vector<T>* ret, int idx, T cur) {
  if (idx == v.size()) {
    ret->push_back(cur);
  }
  else {
    T mul = 1;
    for (int i = 0; i < v[idx].second + 1; i++) {
      tour(v, ret, idx + 1, cur * mul);
      mul *= v[idx].first;
    }
  }
}

template <class T>
vector<T> get_divi(T x) {
  auto v = factor(x);
  vector<T> ret;
  tour(v, &ret, 0, (T)1);
  sort(ret.begin(), ret.end());
  return ret;
}

template <int N>
bitset<N> sieve() {
  bitset<N> bs;
  bs.set();
  bs[0] = 0;
  bs[1] = 0;
  for (int i = 2; i < N; i++) {
    if (bs.test(i)) {
      for (int j = i + i; j < N; j += i) {
        bs.reset(j);
      }
    }
  }
  return bs;
}

template <int N>
vector<int> get_prime() {
  vector<int> prime;
  auto bs = sieve<N>();
  for (int i = 1; i < N; i++) {
    if (bs.test(i)) {
      prime.push_back(i);
    }
  }
  return prime;
}

bool is_prime(ll n) {
  for (ll x = 2; x * x <= n; x++) {
    if (n % x == 0) {
      return false;
    }
  }
  return true;
}
}  // namespace numbers_t

using namespace numbers_t;

const int mod = 1e9 + 7;

int add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

int sub(int& a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}

int mul(int a, int b) { return (int)((ll)a * b % mod); }

int power(int a, ll b) {
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

void solve() {
  ll x, n; cin >> x >> n;
  vector<pair<ll, int>> facts = factors<ll>(x);
  int ans = 1;
  for (auto f : facts) {
    ll cnt = 0;
    ll r = n;
    while (r > 0) {
      r /= f.x;
      cnt += r;
    }
    trace(f, n, cnt);
    ans = mul(ans , power(f.x, cnt));
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
