/* created   : 2022-03-17 19:09:20
 * accepted  : 2022-03-17 19:28:15
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // ai | aj = x | y
  //
  //
  // 11
  //100
  //
  int N; cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 0;
  for (int j = 0; j < 30; j++) {
    int c = 0;
    for (int i = 0; i < N; i++) {
      c += (A[i] >> j & 1);
    }
    if (c > 0) {
      ans |= (1u << j);
    }
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
