/* created   : 2021-05-11 21:52:51
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  string S; cin >> S;
  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    if (i >= 1 && S[i] > S[i - 1]) {
      ans[i] = ans[i - 1] + 1;
    }
    else {
      ans[i] = 1;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
