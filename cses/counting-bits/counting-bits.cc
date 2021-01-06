/* created   : 2021-01-05 22:10:02
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

ll brute_force(ll x) {
  ll ans = 0;
  for (ll i = 1; i <= x; i++) {
    ans += __builtin_popcount(i);
  }
  return ans;
}

void solve() {
  ll N; cin >> N;
  int t = 0;
  while ((1ll << t) <= N) {
    t++;
  }
  ll ans = 0;
  for (int i = 0; i < t; i++) {
    ll cycle = (1ll << i);
    ll step = (N + 1) / cycle;
    ll rem = (N + 1) % cycle;
    // [cycle]
    //  0000  1111  0000  1111  0000  1111
    ans += step / 2 * cycle;
    ans += (step & 1 ? rem : 0);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
