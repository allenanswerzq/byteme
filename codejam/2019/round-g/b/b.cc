/* created   : 2019-10-19 21:47:23
 * accepted  : 2019-10-20 10:49:25
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

void solve() {
  ll n, m; cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // 1000
  // 0010
  // 0100
  //k0000
  ll ans = 0;
  const int BITS = 50;
  vector<int> cnt(BITS);
  for (int i = 0; i < BITS; i++) {
    int one = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] & (1ll << i)) {
        one++;
      }
    }
    cnt[i] = one;
    if (one > n - one) {
      ans |= (1ll << i);
    }
  }
  ll value = 0;
  for (int i = 0; i < n; i++) {
    value += a[i] ^ ans;
  }
  for (int i = BITS - 1; i >= 0; i--) {
    if ((ans & (1ll << i)) == 0) {
      ll one = cnt[i] * (1ll << i);
      ll zero = (n - cnt[i]) * (1ll << i);
      ll tmp = value - one + zero;
      if (tmp <= m) {
        ans |= (1ll << i);
        value = tmp;
      }
    }
  }
  cout << (value <= m ? ans : -1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
