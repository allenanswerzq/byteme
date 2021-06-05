/* created   : 2021-06-05 16:24:08
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (auto& a : A) {
    cin >> a;
  }
  trace(A);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      trace(i, j, A[i], A[j]);
      if (__gcd(A[i], A[j]) == 1) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
