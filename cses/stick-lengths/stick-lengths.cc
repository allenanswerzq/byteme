/* created   : 2020-11-05 19:25:29
 * accepted  : 2020-11-05 21:33:55
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// abs(x - a1) + abs(x - a2) + abs(x - a3) + ...
void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (auto& a : A) {
    cin >> a;
  }
  sort(all(A));
  ll ans = 0;
  int avg = (N & 1 ? A[N / 2] : (A[N / 2] + A[N / 2 - 1]) / 2);
  for (auto a : A) {
    ans += abs(a - avg);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
