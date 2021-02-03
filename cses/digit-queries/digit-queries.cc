/* created   : 2021-02-03 22:22:22
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  // 9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000 + ...
  // int N; cin >> N;
  // while (N--) {
  //   ll K; cin >> K;
  string S;
  for (int i = 0; i < 1000; i++) {
    S += to_string(i);
  }
  for (int j = 1; j <= 1000; j++) {
    ll b = S[j - 1] - '0';
    ll K = j - 1;
    ll c = 0;
    ll t = 9;
    ll p = 0;
    int i = 1;
    while (K >= c) {
      p = c;
      c += i * t;
      t *= 10;
      i++;
    }
    // --------c(i-1)------K------i---
    // trace(K, i, c);
    K -= (p - 1);
    ll d = K / (i - 1);
    ll e = K % (i - 1);
    // trace(K, d, e);
    int ans = 0;
    if (e == 0) {
      ans = (d - 1) % 10;
    }
    else {
      ll x = pow(10, i - 1) + d;
      string s = to_string(x);
      trace(x, s, d, e);
      ans = s[i - e - 1] - '0';
    }
    trace(j, i, K, d, e, ans, b, S.substr(p, 10));
    assert(ans == b);
    // cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
