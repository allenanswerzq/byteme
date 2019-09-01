/* created   : 2019-08-19 20:27:47
 * accepted  : 2019-08-19 20:42:16
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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int lo = -1;
  int hi = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] != i && lo == -1) {
      lo = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] != i && hi == -1) {
      hi = i;
      break;
    }
  }
  trace(lo, hi);
  if (lo == -1 || hi == -1) {
    cout << 0 << ' ' << 0 << '\n';
    return;
  }
  bool ok = 1;
  for (int i = lo; i < hi; i++) {
    if (a[i] < a[i + 1]) {
      ok = 0;
    }
  }
  if (ok) {
    cout << lo << ' ' << hi << '\n';
  }
  else {
    cout << 0 << ' ' << 0 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
