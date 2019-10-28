/* created   : 2019-10-27 23:09:49
 * accepted  : 2019-10-27 23:10:51
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i * j == n) {
        cout << "Yes" << '\n';
        return;
      }
    }
  }
  cout << "No" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
