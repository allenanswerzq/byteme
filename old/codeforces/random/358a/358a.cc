/*
 * created   : 2019-07-25 09:09:55
 * accepted  : 2019-07-25 09:54:16
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  if (n < 3) {
    cout << "no" << "\n";
    return;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  bool ok = 1;
  for (int i = 0; i < n - 1; ++i) {
    int lo = min(a[i], a[i + 1]);
    int hi = max(a[i], a[i + 1]);
    for (int j = 0; j < n - 1; ++j) {
      int x = min(a[j], a[j + 1]);
      int y = max(a[j], a[j + 1]);
      trace(lo, hi, x, y);
      if (x < lo && lo < y && y < hi) {
        ok = 0;
        break;
      }
      if (lo < x && x < hi && hi < y) {
        ok = 0;
        break;
      }
    }
  }
  cout << (!ok ? "yes" : "no") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
