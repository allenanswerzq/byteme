/* created   : 2020-12-26 11:25:05
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  double ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= A[i]; j++) {
      double p = 0;
      for (int k = i + 1; k < N; k++) {
        if (j <= A[k]) {
          p += (j - 1) * 1.0 / A[k];
        }
        else {
          p += 1;
        }
      }
      ans += p * 1.0 / A[i];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << setprecision(6) << fixed;
  solve();
  return 0;
}
