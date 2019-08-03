/*
 * created   : 2019-07-24 09:05:40
 * accepted  : 2019-07-24 09:46:27
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  if (k == 1) {
    cout << (ll) a * (n - 1) << "\n";
    return;
  }
  ll ans = 0;
  while (n != 1) {
    if (n < k) {
      ans += (ll) a * (n - 1);
      break;
    }
    ans += (ll) a * (n % k);
    n -= n % k;
    ans += min((ll) b, (ll) a * (n - n / k));
    n /= k;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
