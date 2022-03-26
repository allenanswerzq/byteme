/* created   : 2022-03-26 10:52:32
 * accepted  : 2022-03-26 14:41:43
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

vector<ll> fact;

void solve() {
  ll N; cin >> N;
  int ans = 1e9;
  for (int i = 0; i < (1ll << 15); i++) {
    ll sum = 0;
    int c = 0;
    for (int j = 0; j < 15; j++) {
      if (i >> j & 1) {
        sum += fact[j];
        c++;
      }
    }
    if (N >= sum) {
      ans = min(ans, __builtin_popcountll(N - sum) + c);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  fact.resize(20, 1);
  fact[0] = 0;
  for (int i = 1; i <= 15; i++) {
    for (int j = 1; j <= i; j++) {
      fact[i] *= j;
    }
    trace(i, bitset<30>(fact[i]));
  }
  trace(fact);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
