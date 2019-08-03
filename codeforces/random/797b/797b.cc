/*
 * created   : 2019-07-27 22:11:42
 * accepted  : 2019-07-27 22:48:20
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
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > 0) {
      sum += a[i];
    }
  }
  if (sum % 2 == 1) {
    cout << sum << "\n";
    return;
  }
  int mi = (1 << 30);
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0 && a[i] % 2 == 1) {
      mi = min(mi, a[i]);
    }
  }
  int mx = -(1 << 30);
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0 && a[i] % 2 == -1) {
      mx = max(mx, a[i]);
    }
  }
  trace(sum, mi, mx);
  cout << sum - min(mi, -mx) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
