/* created   : 2019-08-16 19:40:25
 * accepted  : 2019-08-16 19:48:42
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

const int mod = 1e6 + 3;

void solve() {
  int n;
  cin >> n;
  ll ans = 1;
  for (int i = 0; i < n - 1; i++) {
    ans *= 3;
    ans %= mod;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
