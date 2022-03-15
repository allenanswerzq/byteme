/* created   : 2022-03-15 17:54:34
 * accepted  : 2022-03-15 18:05:16
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  // 1 4 2 3
  int c = 1;
  int i = 0;
  int j = 0;
  while (i < N && A[i] == c) {
    i++, c++, j++;
  }
  while (i < N && A[i] != c) {
    i++;
  }
  if (i < N) {
    assert(A[i] == c);
    reverse(A.begin() + j, A.begin() + i + 1);
  }
  for (int k = 0; k < N; k++) {
    cout << A[k] << (k == N - 1 ? '\n' : ' ');
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
