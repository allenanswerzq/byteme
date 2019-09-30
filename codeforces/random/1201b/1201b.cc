/* created   : 2019-09-08 15:14:51
 * accepted  : 2019-09-08 16:06:31
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  ll sum = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    sum += x;
    mx = max(x, mx);
  }
  if (sum % 2 == 0 && mx <= sum - mx) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
