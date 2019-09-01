/* created   : 2019-08-11 10:47:48
 * accepted  : 2019-08-11 14:42:27
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
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << n - 2 + 1 << "\n";
    return;
  }
  set<int> a, b;
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x < y) {
      swap(x, y);
    }
    a.insert(x);
    b.insert(y);
  }
  if (!a.empty() && !b.empty() && *a.begin() < *b.rbegin()) {
    cout << 0 << "\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (a.count(i) && b.count(i)) {
      cout << 0 << "\n";
      return;
    }
  }
  int k = 0;
  for (int i = 1; i <= n; i++) {
    if (!a.count(i) && !b.count(i)) {
      if (*b.rbegin() < i && i < *a.begin()) {
        k++;
      }
    }
  }
  ans += k + 1;
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
