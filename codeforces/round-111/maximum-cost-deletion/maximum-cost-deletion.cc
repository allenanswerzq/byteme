/* created   : 2021-08-16 07:54:54
 * accepted  : 2021-08-16 08:34:25
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 11001
  // -2 * 2 + 5 = 1
  // -2 * 2 + 5 = 1
  // -2 * 1 + 5 = 3
  int N, A, B; cin >> N >> A >> B;
  string S; cin >> S;
  int c1 = 0;
  for (int i = 0; i < N; i++) {
    c1 += A * 1 + B;
  }
  // 1001110011
  int c2 = 0;
  int c3 = 0;
  int z = 0;
  for (int i = 0; i < N;) {
    int one = 0;
    int zero = 0;
    while (i < N && S[i] == '1') i++, one++;
    while (i < N && S[i] == '0') i++, zero++;
    if (one > 0) {
      c3 += A * one + B;
    }
    if (zero > 0) {
      c2 += A * zero + B;
    }
    z += zero;
    trace(i, c2, c3, zero, one, z);
  }
  if (N - z > 0) {
    c2 += A * (N - z) + B;
  }
  if (z > 0) {
    c3 += A * z + B;
  }
  trace(c1, c2, c3, z);
  cout << max({c1, c2, c3}) << "\n";
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
