/* created   : 2020-03-08 13:01:36
 * accepted  : 2020-03-08 13:13:38
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, p; cin >> n >> p;
  int t = 2 * n + p;
  vector<pair<int, int>> ans;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans.push_back({i, j});
      // trace(t, ans);
      if ((int) ans.size() == t) {
        for (int k = 0; k < t; k++) {
          // trace(k, ans);
          cout << ans[k].x << ' ' << ans[k].y << '\n';
        }
        return;
      }
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
