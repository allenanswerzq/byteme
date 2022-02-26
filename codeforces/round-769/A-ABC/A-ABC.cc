/* created   : 2022-02-26 11:34:14
 * accepted  : 2022-02-26 11:40:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 010
  // 0101
  // 00011
  // 000011111
  // 01011110
  int N; cin >> N;
  string S; cin >> S;
  int z = 0;
  for (int i = 0; i < N; i++) {
    z += (S[i] == '0');
  }
  if ((N == 1) || (z == 1 && N == 2)) {
    cout << "YES\n";
    return;
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
