/* created   : 2020-03-06 00:02:09
 * accepted  : 2020-03-06 18:57:57
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
  int n; cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '.') {
        ans.push_back({i, j});
        break;
      }
    }
  }
  if ((int) ans.size() == n) {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].x + 1 << ' ' << ans[i].y + 1 << '\n';
    }
    return;
  }
  ans.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j][i] == '.') {
        ans.push_back({j, i});
        break;
      }
    }
  }
  if ((int) ans.size() == n) {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].x + 1 << ' ' << ans[i].y + 1 << '\n';
    }
    return;
  }
  cout << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
