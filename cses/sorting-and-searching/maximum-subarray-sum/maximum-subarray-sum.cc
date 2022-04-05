/* created   : 2020-11-05 19:20:43
 * accepted  : 2020-11-05 19:23:28
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  ll ans = -1e9;
  ll pre = 0;
  // f[i] = max(x, f[i-1] + a[i])
  for (int i = 0; i < N; i++) {
    ll x; cin >> x;
    ll cur = max(x, pre + x);
    ans = max(ans, cur);
    pre = cur;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
