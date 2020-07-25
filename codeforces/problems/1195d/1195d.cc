/* created   : 2019-10-19 00:10:43
 * accepted  : 2019-10-19 01:03:54
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

// 312 745 45
// 312,745  371425
// 745,312  734152

// 1-1 12,12 1100

// 1-2 12,33 1323
// 2-1 33,12 3132

// 1-3 12,45 1425
// 3-1 45,12 4152

// 2-2 33,33 3333

// 2-3 33,45 3435
// 3-2 45,33 4353

// 3-3 45,45 4455

// 10,10 1100
void solve() {
  int n; cin >> n;
  int ans = 0;
  const int mod = 998244353;
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    reverse(x.begin(), x.end());
    trace(i, x);
    ll p = 1;
    for (int j = 0; j < (int) x.size(); j++) {
      ll d = x[j] - '0';
      ans += n % mod * (p * d + p * 10 * d) % mod;
      ans %= mod;
      p *= 100;
      p %= mod;
      trace(j, ans, p);
    }
  }
  cout << ans % mod << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
