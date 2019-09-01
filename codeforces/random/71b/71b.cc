/* created   : 2019-08-14 10:57:34
 * accepted  : 2019-08-14 11:04:49
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
  int n, k, t;
  cin >> n >> k >> t;
  vector<int> ans(n);
  int z = n * k * t / 100;
  int x = z / k;
  int y = z % k;
  for (int i = 0; i < n; i++) {
    if (i < x) {
      ans[i] = k;
    }
    else if (i == x) {
      ans[i] = y;
    }
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
