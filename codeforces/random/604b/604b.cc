/*
 * creat   : 2019-07-19 17:30:59
 * accept  : 2019-07-19 20:20:35
 * author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (k >= n) {
    cout << a[n - 1] << "\n";
    return;
  }
  int ans = 0;
  for (int i = 0; i < n - k; ++i) {
    int tmp = a[i] + a[2 * (n - k) - i - 1];
    ans = max(tmp, ans);
  }
  for (int i = 2 * (n - k); i < n; ++i) {
    ans = max(ans, a[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
