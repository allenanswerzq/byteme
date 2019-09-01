/* created   : 2019-08-10 08:48:57
 * accepted  : 2019-08-10 09:12:47
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
  int n, k;
  cin >> n >> k;
  int ans = 0;
  int pr = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    int x = (pr + k - 1) / k;
    ans += x;
    t -= min(x * k - pr, t);
    if (i == n - 1) {
      ans += (t + k - 1) / k;
    }
    else {
      ans += t / k;
      pr = t % k;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
