/* created   : 2019-08-29 10:24:58
 * accepted  : 2019-08-29 10:27:27
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  double ans = (a[0] + a[1]) / 2.0;
  for (int i = 2; i < n; i++) {
    ans = (ans + a[i]) / 2.0;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  cout << fixed << setprecision(20);
  return 0;
}
