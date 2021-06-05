/* created   : 2021-06-05 09:30:56
 * accepted  : 2021-06-05 11:48:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = unsigned long long;
using ar = array<int, 2>;

// https://cp-algorithms.com/combinatorics/inclusion-exclusion.html
void solve() {
  ll N, K; cin >> N >> K;
  vector<ll> A(K);
  for (auto & a : A) {
    cin >> a;
  }
  trace(A);
  ll ans = 0;
  for (int s = 1; s < (1ll << K); s++) {
    ll cnt = 0;
    ll t = N;
    // NOTE: unsigned variable will not overflow
    // ll mul = 1;
    for (int i = 0; i < K; i++) {
      if (s & (1 << i)) {
        cnt++;
        t /= A[i];
        // mul *= A[i];
      }
    }
    if (cnt & 1) {
      ans += t;
    }
    else {
      ans -= t;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
