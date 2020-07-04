/* created   : 2020-07-04 09:03:04
 * accepted  : 2020-07-04 09:08:50
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  ll n, k; cin  >> n >> k;
  ll ans = n * k;
  int g;
  // sum[i, i + 1, ... g] = (g + i) * (g - i + 1) / 2;
  for (int i = 1; i <= n; i = g + 1) {
    // k / g = k / i
    g = k / i == 0 ? n : min(k / (k / i), n);
    ans -= k / i * (g + i) * (g - i + 1) / 2;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
