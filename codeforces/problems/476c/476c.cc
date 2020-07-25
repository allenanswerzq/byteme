/* created   : 2020-05-04 19:25:52
 * accepted  : 2020-05-04 19:44:07
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int mod = 1e9 + 7;

void solve() {
  ll a, b; cin >> a >> b;
  int ans = 0;
  for (int k = 1; k <= a; k++) {
    ll x = b * (b - 1) / 2;
    x %= mod;
    ll y = k * b + 1;
    y %= mod;
    ans += x * y % mod;
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
