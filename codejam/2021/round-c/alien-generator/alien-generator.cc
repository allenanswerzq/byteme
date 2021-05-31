/* created   : 2021-05-29 15:59:18
 * accepted  : 2021-05-30 09:30:37
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  ll G; cin >> G;
  // d * k + d * (d - 1) / 2 = G >= d * (d - 1) / 2
  // ==> 2 * G >= d * (d - 1)
  // ==> d <= sqrt(2 * G)
  ll ans = 0;
  // 1 <= d <= sqrt(2 * G)
  for (ll d = 1; d <= (ll) sqrt(2 * G); d++) {
    ll lo = 0;
    ll hi = G;
    // binary search on k
    while (lo + 1 < hi) {
      ll md = lo + (hi - lo) / 2;
      if (d * md + d * (d - 1) / 2 > G) {
        hi = md;
      }
      else {
        lo = md;
      }
    }
    if (d * lo + d * (d - 1) / 2 == G) {
      trace(d, lo, hi);
      ans++;
    }
  }
  cout << ans + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
