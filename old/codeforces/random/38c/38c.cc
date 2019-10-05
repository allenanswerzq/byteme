/* created   : 2019-08-25 22:02:03
 * accepted  : 2019-08-25 22:10:13
 * author    : THeAnswer
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
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int l = m; l <= 100; l++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur += a[i] / l;
    }
    ans = max(ans, cur * l);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
