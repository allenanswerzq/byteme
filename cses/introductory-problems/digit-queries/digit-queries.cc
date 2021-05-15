/* created   : 2021-02-04 11:35:51
 * accepted  : 2021-02-04 13:08:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

string S;

void solve(ll K) {
  // ll K; cin >> K;
  ll W = K;
  // int b = S[K] - '0';
  ll c = 0;
  ll t = 9;
  ll i = 1;
  ll p = 0;
  while (K >= c) {
    p = c;
    c += (i == 1 ? 10 : i * t);
    t *= 10;
    i++;
  }
  // 0-9  10-99
  // 10 + 2 * 90 + 3 * 900
  // 012345678910
  // -------c(i-1)----K------i
  K -= p;
  ll d = K / (i - 1);
  ll r = K % (i - 1);
  ll x = (i == 2 ? 0 : (ll)pow(10, i - 2)) + d;
  string s = to_string(x);
  // reverse(all(s));
  int ans = s[r] - '0';
  // assert(ans == b);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  // for (int i = 0; i < 10000; i++) {
  //   S += to_string(i);
  // }
  while (t--) {
    // for (int i = 0; i < 10000; i++) {
    ll i; cin >> i;
    solve(i);
    // }
  }
  return 0;
}
