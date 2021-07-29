/* created   : 2021-07-29 06:55:29
 * accepted  : 2021-07-29 06:57:13
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  string S; cin >> S;
  int a = 0;
  for (char c : S) {
    if (c == 'A') {
      a++;
    }
    else {
      a--;
    }
  }
  cout << (a > 0 ? 'A' : a == 0 ? 'T' : 'B') << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
