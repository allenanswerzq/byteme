/* created   : 2021-06-05 06:32:10
 * accepted  : 2021-06-05 09:16:56
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

const int mod = 1e9 + 7;

ll mul(ll a, ll b) { return (a * b % mod); }

ll power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

ll gemometic_series(ll p, ll c) {
  // 1 + p + p * p + ... +
  // return (power(p, c + 1) - 1) / (p - 1);
  return (power(p, c + 1) - 1) % mod * power(p - 1, mod - 2) % mod;
}

// NOTE: Fermat's little theorem
//  1. a^m === a (mod m) m is a prime
//  2. a^(m - 1) === 1 (mod m)
//  3. a^b % m == a^(b % m - 1) % m
void solve() {
  int N; cin >> N;
  ll cnt = 1;
  ll cnt2 = 1;
  ll sum = 1;
  ll prod = 1;
  for (int i = 0; i < N; i++) {
    ll p, c; cin >> p >> c;
    cnt = cnt * (c + 1) % mod;
    sum = sum * gemometic_series(p, c) % mod;
    prod = power(prod, c + 1) * power(power(p, c * (c + 1) / 2), cnt2) % mod;
    cnt2 = cnt2 * (c + 1) % (mod - 1);
  }
  cout << cnt << " " << sum << " " << prod << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
