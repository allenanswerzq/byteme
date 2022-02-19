/* created   : 2022-02-13 20:48:34
 * accepted  : 2022-02-13 21:58:21
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 1 2 3 4 5 6 k
  //           4 h
  //     1 2 3 4
  //
  // 1 2 3 4 5 k
  //       2 2 h
  //     1 2 3
  //
  // 1 2 3 4 5 6 7 8 9  k
  //         2   1   2  h
  //       1 2   1 1 2
  //
  int N; cin >> N;
  vector<ll> K(N);
  for (int i = 0; i < N; i++) {
    cin >> K[i];
  }
  vector<ll> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  vector<ll> A = H;
  // A[i] stands the mininum height ith position should have
  for (int i = N - 2; i >= 0; i--) {
    ll d = K[i + 1] - K[i];
    ll mi = max(A[i + 1], H[i + 1]);
    A[i] = max({mi - d, H[i]});
  }
  trace(A);
  ll ans = A[0] * (A[0] + 1) / 2;
  for (int i = 1; i < N; i++) {
    ll d = K[i] - K[i - 1];
    if (d >= A[i]) {
      ans += A[i] * (A[i] + 1) / 2;
    }
    else {
      assert(A[i - 1] + d >= A[i]);
      A[i] = A[i - 1] + d;
      // a+1, a+2, ..., a+d
      ans += d * (d + 1) / 2 + d * A[i - 1];
    }
  }
  trace(A);
  cout << ans << "\n";
  // 1 2 3 4 5 6 7 8 9 10
  //   1 2 3 4 5 6     3
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
