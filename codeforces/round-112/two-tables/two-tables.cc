/* created   : 2021-08-13 21:22:14
 * accepted  : 2021-08-13 22:29:01
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int W, H; cin >> W >> H;
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int w, h; cin >> w >> h;
  const int INF = 1e9 + 7;
  int ans = INF;
  if (h + y2 - y1 <= H) {
    if (w <= W) {
      int h1 = max(0, h - (H - y2));
      int h2 = max(0, h - y1);
      ans = min(h1, h2);
    }
  }
  if (w + x2 - x1 <= W) {
    if (h <= H) {
      int w1 = max(0, w - x1);
      int w2 = max(0, w - (W - x2));
      ans = min({ans, w1, w2});
    }
  }
  cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(9);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
