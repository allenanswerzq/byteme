/* created   : 2022-03-11 20:22:56
 * accepted  : 2022-03-11 20:30:56
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  //                aba
  //        aabbaa         baaaab
  // aabbaaaabbaa        baaaabbaaaab
  //
  int N, K; cin >> N >> K;
  string S; cin >> S;
  bool ok = true;
  for (int i = 0, j = N - 1; i < j; i++, j--) {
    if (S[i] != S[j]) {
      ok = false;
      break;
    }
  }
  if (ok || K == 0) {
    cout << "1\n";
  }
  else {
    cout << "2\n";
  }
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
