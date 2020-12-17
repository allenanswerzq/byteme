/* created   : 2020-12-17 22:07:14
 * accepted  : 2020-12-17 22:15:34
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    int ans = 1;
    for (int j = 2; j * j <= x; j++) {
      int t = 1;
      if (x % j == 0) {
        while (x % j == 0) {
          x /= j;
          t++;
        }
        ans *= t;
      }
    }
    if (x > 1) {
      ans *= 2;
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
