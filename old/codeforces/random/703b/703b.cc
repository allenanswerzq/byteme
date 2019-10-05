/*
 * created   : 2019-07-22 22:37:02
 * accepted  : 2019-07-22 23:24:49
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  vector<bool> was(n);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    was[--x] = 1;
  }
  // c3 * (c1 + c2 + c4 + c3) - c3 * c3;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!was[i] && !was[(i + 1) % n]) {
      ans += a[i] * a[(i + 1) % n];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (was[i]) {
      ans += a[i] * sum - a[i] * a[i];
      sum -= a[i];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
