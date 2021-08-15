/* created   : 2021-08-08 13:49:09
 * accepted  : 2021-08-08 13:52:40
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  vector<ll> pr(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    pr[i + 1] = pr[i] + A[i];
  }
  int ans = 0;
  for (int i = 0; i + 1 < N; i++) {
    if (pr[i + 1] == pr[N] - pr[i + 1]) {
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
