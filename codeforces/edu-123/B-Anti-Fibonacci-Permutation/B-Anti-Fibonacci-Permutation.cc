/* created   : 2022-03-21 20:57:15
 * accepted  : 2022-03-21 22:11:00
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void check(vector<int> & v) {
  for (int i = 0; i + 2 < v.size(); i++) {
    assert(v[i] + v[i + 1] != v[i + 2]);
  }
}

void solve() {
  int N; cin >> N;
  // pi-2 + pi-1 != pi
  vector<int> A(N);
  iota(all(A), 1);
  reverse(all(A));
  for (int i = 0; i < N; i++) {
    if (N == 3 && i == N - 1) {
      swap(A[0], A[2]);
    }
    check(A);
    for (int j = 0; j < N; j++) {
      cout << A[j] << (j == N - 1 ? '\n' : ' ');
    }
    rotate(A.begin(), A.begin() + N - 1, A.end());
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
