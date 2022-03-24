/* created   : 2022-03-24 09:05:39
 * accepted  : 2022-03-24 09:27:46
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, X; cin >> N >> X;
  map<ll, int> mp;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    mp[x]++;
  }
  for (auto & it : mp) {
    ll c = it.first;
    if (mp[c] == 0) continue;
    if (mp[c * X]) {
      int t = min(mp[c], mp[c * X]);
      mp[c] -= t;
      mp[c * X] -= t;
    }
  }
  trace(mp);
  ll ans = 0;
  for (auto & it : mp) {
    ans += mp[it.first];
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
