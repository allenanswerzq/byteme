/* Name        : e
 * Creat       : Sat Jul 13 09:34:01 CST 2019
 * Accept      : Sat Jul 13 10:19:15 CST 2019
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
  int n, k;
  cin >> n >> k;
  int mx = (n - 1) * (n - 2) / 2;
  if (k > mx) {
    cout << -1 << "\n";
    return;
  }
  vector<pair<int, int>> ans;
  for (int i = 2; i <= n; ++i) {
    ans.emplace_back(i, 1);
  }
  int extra = mx - k;
  for (int i = 2; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (extra-- > 0) {
        ans.emplace_back(i, j);
      }
    }
  }
  cout << sz(ans) << "\n";
  for (int i = 0; i < sz(ans); ++i) {
    cout << ans[i].x << " " << ans[i].y << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
