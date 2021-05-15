/* created   : 2021-01-12 22:17:04
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
  A.push_back(0);
  N++;
  vector<int> stk;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    while (stk.size() && A[i] < A[stk.back()]) {
      int height = A[stk.back()];
      stk.pop_back();
      int p = stk.size() ? stk.back() : -1;
      ans = max(ans, (i - p - 1) * 1ll * height);
    }
    stk.push_back(i);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
