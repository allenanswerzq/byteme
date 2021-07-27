/* created   : 2021-07-26 23:14:00
 * accepted  : 2021-07-26 23:25:13
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  int N, K; cin >> N >> K;
  vector<ll> A(N);
  for (ll& a : A) {
    cin >> a;
  }
  sort(all(A));
  trace(A);
  for (int i = 0; i < min(K, N - 1); i++) {
    A[N - 1] += A[N - 2 - i];
  }
  cout << A[N - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
