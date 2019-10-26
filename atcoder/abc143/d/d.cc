/* created   : 2019-10-26 08:55:09
 * accepted  : 2019-10-26 10:00:56
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
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  vector<int> use(n);
  int ans = 0;
  // abs(a - b) < c < a + b
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int a = v[i];
      int b = v[j];
      int x = upper_bound(v.begin() + j + 1, v.end(), abs(a - b)) - v.begin();
      int y = lower_bound(v.begin() + j + 1, v.end(), a + b) - v.begin();
      ans += (y - x);
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
