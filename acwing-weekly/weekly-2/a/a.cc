/* created   : 2021-07-26 22:58:43
 * accepted  : 2021-07-26 23:02:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  int N; cin >> N;
  for (int x = 0; x <= N / 3; x++) {
    for (int y = 0; 3 * x + 5 * y <= N; y++) {
      int z = N - 3 * x - 5 * y;
      if (z >= 0 && z % 7 == 0) {
        cout << x << " " << y << " " << z / 7 << "\n";
        return;
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
