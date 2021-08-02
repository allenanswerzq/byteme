/* created   : 2021-08-01 16:31:06
 * accepted  : 2021-08-02 08:41:45
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  ll N, C; cin >> N >> C;
  vector<ar> A(N);
  map<ll, int> mp;
  for (int i = 0; i < N; i++) {
    cin >> A[i][0] >> A[i][1];
    mp[A[i][0] + 1] += 1;
    mp[A[i][1]] -= 1;
  }
  trace(mp);
  vector<ll> count(N + 1);
  int cut = 0;
  ll pre = -1;
  for (auto it : mp) {
    count[cut] += (pre == -1 ? 0 : it.first - pre);
    cut += it.second;
    pre = it.first;
  }
  trace(count);
  ll ans = N;
  for (ll i = N; i >= 0 && C > 0; i--) {
    ans += i * min(count[i], C);
    C -= min(count[i], C);
  }
  cout << ans << "\n";
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
