/* created   : 2021-11-13 15:15:09
 * accepted  : 2021-11-13 15:20:09
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  int up = 0;
  int down = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    if (x == 1) {
      up++;
    }
    else if (x == 2) {
      down++;
    }
    else {
      up++;
    }
  }
  cout << up << "\n";
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
