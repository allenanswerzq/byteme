/* created   : 2020-11-01 10:40:58
 * accepted  : 2020-11-01 10:49:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  int ans = 0;
  // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 ... 20
  int five = 5;
  while (five <= n) {
    ans += n / five;
    five *= 5;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
