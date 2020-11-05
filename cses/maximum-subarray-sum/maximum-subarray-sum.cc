/* created   : 2020-11-05 19:20:43
 * accepted  : 2020-11-05 19:23:28
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  ll cur = 0;
  ll ans = -1e9;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    cur += x;
    ans = max(ans, cur);
    cur = max(cur, 0ll);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
