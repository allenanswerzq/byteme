/* created   : 2022-02-19 16:27:27
 * accepted  : 2022-02-19 16:29:52
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  // 1 2 6 5 1 2
  // 3 4 3 2 2 5
  //
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
    if (A[i] > B[i]) {
      swap(A[i], B[i]);
    }
  }
  int ma = *max_element(all(A));
  int mb = *max_element(all(B));
  cout << ma * mb << "\n";
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
