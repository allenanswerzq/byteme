/* created   : 2022-03-17 19:34:57
 * accepted  : 2022-03-17 19:58:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 1 2 3 1
  // 1 2 1 2 1
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int ans = 0;
  for (int i = 1; i < N - 1; i++) {
    if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
      //  /       \
      // i-1, i, i+1, i+2
      A[i + 1] = max(A[i], i + 2 < N - 1 ? A[i + 2] : A[i]);
      ans++;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < N; i++) {
    cout << A[i] << (i == N - 1 ? '\n' : ' ');
  }
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
