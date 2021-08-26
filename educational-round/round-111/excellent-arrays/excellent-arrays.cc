/* created   : 2021-08-25 07:49:15
 * accepted  : 2021-08-27 07:45:50
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

template <int MOD>
struct CombinaLarge {
  vector<ll> fact;
  vector<ll> fact_inv;

  explicit CombinaLarge(int n) {
    fact.resize(n + 1);
    fact_inv.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
    }
    fact_inv[n] = power(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i) {
      fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;
    }
  }

  ll power(ll x, int p){
    ll ans = 1;
    while (p > 0) {
      if (p & 1) {
        ans = x * ans % MOD;
      }
      x = x * x % MOD;
      p >>= 1;
    }
    return ans;
  }

  // Choose k from total n items without permutation
  int nck(int n, int k) { return (*this)(n, k); }

  // Choose k from total n items with permutation
  int npk(int n, int k) {
    // nPk = nCk * k!
    ll ret = nck(n, k);
    ret = ret * fact[k] % MOD;
    return ret % MOD;
  }

  int operator()(int n, int k) {
    if (k < 0 || n < k) {
      return 0;
    }
    return fact[n] * fact_inv[k] % MOD * fact_inv[n - k] % MOD;
  }
};

void solve() {
  int N, L, R; cin >> N >> L >> R;
  ll k = min(R - N, -(L - 1));
  const int mod = 1e9+7;
  CombinaLarge<mod> comb(N + 7);

  int ans = 0;
  ans += k * comb.nck(N, N / 2) % mod;
  if (N & 1) {
    ans += k * comb.nck(N, N - N / 2) % mod;
  }
  // NOTE: the best array must have half x=ai-i  and half -x
  for (int i = N - 1; i >= 1; i--) {
    int x = k + i;
    // i + k <= r ==> i <= r - k
    // i - k >= l ==> i >= l + k
    int pos = min(N, R - x);
    int neg = min(N, N - L - x + 1);
    if (pos < 0 || neg < 0) {
      // Can not make this array into x and -x.
      break;
    }
    int both = N - (N - pos) - (N - neg);
    pos -= both;
    neg -= both;
    if (N & 1) {
      ans = (ans + comb.nck(both, N / 2 - pos)) % mod;
      ans = (ans + comb.nck(both, N / 2 - neg)) % mod;
    }
    else {
      ans = (ans + comb.nck(both, N / 2 - pos)) % mod;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
