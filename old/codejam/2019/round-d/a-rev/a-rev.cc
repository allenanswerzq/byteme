/* created   : 2019-08-24 22:05:26
 * accepted  : 2019-08-25 10:45:01
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

void solve(int tc) {
  int n, q; cin >> n >> q;
  set<int> odd;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (__builtin_popcount(x) % 2) {
      odd.insert(i);
    }
  }
  trace(n, q, odd);
  cout << "Case #" << tc << ":";
  for (int i = 0; i < q; i++) {
    int x, y; cin >> x >> y;
    odd.erase(x);
    if (__builtin_popcount(y) % 2) {
      odd.insert(x);
    }
    int ans = -1;
    if ((int) odd.size() % 2 == 0) {
      ans = n;
    }
    else {
      ans = max(ans, n - *odd.begin() - 1);
      ans = max(ans, *odd.rbegin());
    }
    if (i >= 0) {
      cout << ' ';
    }
    trace(i, x, y, ans, odd);
    cout << ans;
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
