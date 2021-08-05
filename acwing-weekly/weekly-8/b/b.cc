/* created   : 2021-08-05 08:32:52
 * accepted  : 2021-08-05 22:43:29
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  map<int, ll> mp;
  for (int i = 1; i <= N; i++) {
    int a; cin >> a;
    mp[a - i] += a;
  }
  ll ans = 0;
  for (auto it : mp) {
    ans = max(ans, it.second);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
