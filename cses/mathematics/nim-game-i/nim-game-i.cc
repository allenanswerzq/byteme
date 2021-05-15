/* created   : 2020-12-27 10:38:51
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  int s = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    s ^= x;
  }
  cout << (s ? "first" : "second") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
