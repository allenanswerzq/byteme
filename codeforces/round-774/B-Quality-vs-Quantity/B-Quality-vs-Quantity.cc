/* created   : 2022-03-26 10:19:37
 * accepted  : 2022-03-26 10:29:09
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
  sort(all(A));
  vector<ll> pre(N + 1);
  for (int i = 0; i < N; i++) {
    pre[i + 1] = pre[i] + A[i];
  }
  for (int len = 1; len + len + 1 <= N; len++) {
    ll red = pre[N] - pre[N - len];
    ll blue = pre[len + 1];
    trace(A, red, blue);
    if (red > blue) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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
