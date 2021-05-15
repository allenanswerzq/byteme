/* created   : 2020-11-08 21:15:43
 * accepted  : 2020-11-08 21:25:56
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, X; cin >> N >> X;
  vector<array<int, 2>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i][0];
    A[i][1] = i + 1;
  }
  sort(all(A));
  for (int i = 0; i < N; i++) {
    while (i + 1 < N && A[i] == A[i + 1]) i++;
    int lo = i + 1;
    int hi = N - 1;
    trace(A, i, lo, hi);
    while (lo + 1 <= hi) {
      int s = A[i][0] + A[lo][0] + A[hi][0];
      if (s == X) {
        cout << A[i][1] << " " << A[lo][1] << " " << A[hi][1] << "\n";
        return;
      }
      else if (s > X) {
        hi--;
      }
      else {
        lo++;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
