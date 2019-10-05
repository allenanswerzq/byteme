/* Name        : c
 * Creat       : Sat Jul 13 14:58:04 CST 2019
 * Accept      : Sat Jul 13 15:01:20 CST 2019
 * Author      : landcold7
 * Motto       : Action speaks louder more than words
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
  int n, m;
  cin >> n >> m;
  int lo = 0;
  int hi = (1 << 30);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    lo = max(lo, x);
    hi = min(hi, y);
  }
  trace(lo, hi);
  int ans = 0;
  if (lo <= hi) {
    ans = hi - lo + 1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
