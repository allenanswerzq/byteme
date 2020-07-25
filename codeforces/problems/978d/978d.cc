/* created   : 2020-02-23 15:04:36
 * accepted  : 2020-02-23 15:25:18
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
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int INF = 1e5 + 7;
  int ans = INF;
  for (auto dx : {-1, 0, 1}) {
    for (auto dy : {-1, 0, 1}) {
      vector<int> b = a;
      b[0] += dx;
      b[1] += dy;
      int diff = b[1] - b[0];
      int cur = (dx != 0) + (dy != 0);
      for (int i = 2; i < n; i++) {
        if (b[i] - b[i - 1] != diff) {
          if (abs(b[i - 1] + diff - b[i]) <= 1) {
            cur++;
            b[i] = b[i - 1] + diff;
          }
          else {
            cur = -1;
            break;
          }
        }
      }
      trace(dx, dy, diff, cur);
      if (cur != -1) {
        ans = min(ans, cur);
      }
    }
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
