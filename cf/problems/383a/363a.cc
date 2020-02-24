/* created   : 2020-02-24 20:15:48
 * accepted  : 2020-02-24 22:00:44
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

void solve() {
  int n; cin >> n;
  ll ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x == 1) {
      cnt++;
    }
    else {
      ans += cnt;
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
