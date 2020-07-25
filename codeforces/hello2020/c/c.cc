/* created   : 2020-01-05 16:54:50
 * accepted  : 2020-01-05 17:37:12
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 2.5e5 + 7;
ll fact[N];

void solve() {
  int n, mod; cin >> n >> mod;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (ll) fact[i - 1] * i % mod;
  }
  ll ans = 0;
  for (int len = 1; len <= n; len++) {
    // The number of framed subsegment is n - len + 1;
    ans += (ll) (n - len + 1) * (fact[len] * fact[n - len + 1] % mod);
    ans %= mod;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
