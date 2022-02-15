/* created   : 2022-02-15 22:51:38
 * accepted  : 2022-02-15 22:54:56
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, K; cin >> N >> K;
  vector<ar> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i][0];
  }
  for (int i = 0; i < N; i++) {
    cin >> A[i][1];
  }
  sort(all(A));
  trace(A);
  for (int i = 0; i < N; i++) {
    if (K >= A[i][0]) {
      K += A[i][1];
    }
  }
  cout << K << "\n";
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
