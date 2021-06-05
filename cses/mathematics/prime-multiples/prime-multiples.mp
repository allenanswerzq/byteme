/* created   : 2021-06-05 10:51:00
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  ll N, K; cin >> N >> K;
  vector<ll> A(K);
  for (auto & a : A) {
    cin >> a;
  }
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    for (auto a : A) {
      if (i % a == 0) {
        ans++;
        break;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
