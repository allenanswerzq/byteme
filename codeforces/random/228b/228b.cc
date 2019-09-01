/* created   : 2019-08-16 00:00:06
 * accepted  : 2019-08-16 00:34:20
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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int h, w;
  cin >> h >> w;
  vector<string> b(h);
  for (int i = 0; i < h; i++) {
    cin >> b[i];
  }
  auto get = [&](int x, int y) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (0 <= i + x && i + x < h && 0 <= j + y && j + y < w) {
          ret += (a[i][j] - '0') * (b[i + x][j + y] - '0');
        }
      }
    }
    return ret;
  };
  trace(a, b);
  pair<int, int> ans;
  int mx = 0;
  for (int i = -100; i <= 100; i++) {
    for (int j = -100; j <= 100; j++) {
      int cur = get(i, j);
      if (cur > mx) {
        mx = cur;
        ans = {i, j};
      }
    }
  }
  cout << ans.x << " " << ans.y << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
