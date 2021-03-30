/* created   : 2021-03-27 19:45:56
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  int c = 0;
  for (int i = 0; i < N / 2; i++) {
    c += (S[i] != S[N - 1 - i]);
  }
  cout << (c == K ? 0 : abs(c - K)) << "\n";
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
