/*
 * created   : 2019-08-05 00:11:26
 * accepted  : 2019-08-05 00:17:42
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
  for (int i = 0; i < n + 1; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  ll ans = 0;
  for (int i = 0; i < n + 1; i++) {
    int pr = 0;
    if (i > 0) {
      pr += b[i - 1];
    }
    int x = min(pr, a[i]);
    ans += x;
    a[i] -= x;
    if (i < n) {
      int y = min(b[i], a[i]);
      ans += y;
      b[i] -= y;
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
