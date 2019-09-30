/* created   : 2019-09-13 10:39:37
 * accepted  : 2019-09-13 16:14:05
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
  int n, m, k; cin >> n >> m >> k;
  int x = 0;
  int y = 0;
  int turn = 0;
  vector<pair<int, int>> ans;
  while (x < n) {
    ans.emplace_back(x, y);
    if (turn == 0) {
      y++;
      if (y == m) {
        x++, y = m - 1;
        turn = 1;
      }
    }
    else {
      y--;
      if (y == -1) {
        x++, y = 0;
        turn = 0;
      }
    }
  }
  trace(ans);
  for (int i = 0; i < 2 * (k - 1); i += 2) {
    cout << 2 << ' ';
    for (int j = 0; j < 2; j++) {
      cout << ans[i + j].x + 1 << ' ' << ans[i + j].y + 1 << ' ';
    }
    cout << '\n';
  }
  int sz = (int) ans.size();
  cout << sz - 2 * (k - 1) << ' ';
  for (int i = 2 * (k - 1); i < sz; i++) {
    cout << ans[i].x + 1 << ' ' << ans[i].y + 1 << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
