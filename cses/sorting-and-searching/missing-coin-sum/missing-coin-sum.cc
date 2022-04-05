/* created   : 2021-02-05 21:26:38
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (auto& a : A) {
    cin >> a;
  }
  sort(all(A));
  trace(A);
  ll ans = 1; // next value to check
  for (int i = 0; i < N; i++) {
    if (ans < A[i]) {
      break;
    }
    else {
      // can: [1 ... ans - 1] ==> ai+1 ... ai + ans - 1
      ans += A[i];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
