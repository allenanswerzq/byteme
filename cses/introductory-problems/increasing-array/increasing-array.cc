/* created   : 2020-10-29 22:24:58
 * accepted  : 2020-10-29 22:27:43
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (auto& a : A) cin >> a;
  ll ans = 0;
  int mx = A[0];
  for (int i = 1; i < N; i++) {
    ans += (A[i] > mx ? 0 : abs(A[i] - mx));
    mx = max(mx, A[i]);
  }
  cout << ans << "\n";
}

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (auto& a : A) cin >> a;
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    if (A[i] < A[i - 1]) {
      ans += A[i - 1] - A[i];
      A[i] = A[i - 1];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
