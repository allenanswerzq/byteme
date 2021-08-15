/* created   : 2021-08-08 13:54:30
 * accepted  : 2021-08-08 14:42:00
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 26>;

void solve() {
  string S; cin >> S;
  vector<ll> g(26);
  vector<ar> f(26);
  for (char c : S) {
    c -= 'a';
    for (int i = 0; i < 26; i++) {
      // The number of substring that is `ic`
      f[i][c] += g[i];
    }
    g[c]++;
  }
  ll ans = 0;
  for (int i = 0; i < 26; i++) {
    ans = max(ans, g[i]);
    for (int j = 0; j < 26; j++) {
      // trace(i, j, f[i][j]);
      ans = max(ans, f[i][j]);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
