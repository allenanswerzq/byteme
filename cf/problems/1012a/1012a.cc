/* created   : 2020-02-11 21:54:12
 * accepted  : 2020-02-11 22:48:08
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 2e5 + 7;
ll a[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 2 * n + 1);
  ll ans = 1e18 + 7;
  for (int i = 2; i <= n; i++) {
    ans = min(ans, (a[2 * n] - a[1]) * (a[i + n - 1] - a[i]));
  }
  ans = min(ans, (a[n] - a[1]) * (a[2 * n] - a[n + 1]));
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
