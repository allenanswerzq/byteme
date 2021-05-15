/* created   : 2020-12-26 22:26:32
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, K; cin >> N >> K;
  vector<int> A(K);
  for (int i = 0; i < K; i++) {
    cin >> A[i];
  }
  trace(A);
  vector<int> f(N + 1);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < K; j++) {
      if (i >= A[j]) {
        f[i] |= !f[i - A[j]];
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << (f[i] ? "W" : "L");
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
