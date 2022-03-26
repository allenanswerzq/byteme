/* created   : 2022-03-26 10:06:37
 * accepted  : 2022-03-26 10:16:29
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // x *n^2 + (n + 1 - x) * ai = s
  // 0<= (n+1-x) * ai = s - x*n^2 < (n+1-x)*n
  // x*n^2 <= s < (n+1-x)*n + x*n^2=n(n+1) + (n^2-n)x
  // s-(n+1)*n / (n^2-n)  < x <= s / n^2
  ll N, S; cin >> N >> S;
  // if (N == 1) {
  //   cout << S << "\n";
  //   return;
  // }
  ll hi = S / N / N;
  // ll lo = (S - (N + 1) * N) / (N * N - N);
  // trace(lo, hi);
  cout << hi << "\n";
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
