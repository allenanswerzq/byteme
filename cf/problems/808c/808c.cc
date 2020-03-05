/* created   : 2020-03-04 23:05:20
 * accepted  : 2020-03-04 23:16:47
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
  int n, w; cin >> n >> w;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(all(a));
  reverse(all(a));
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (w <= 0) {
      cout << -1 << '\n';
      return;
    }
    ans[a[i].y] = (a[i].x + 1) / 2;
    w -= (a[i].x + 1) / 2;
  }
  assert(w >= 0);
  for (int i = 0; i < n && 0 < w; i++) {
    int p = a[i].y;
    int d = min(w, a[i].x - ans[p]);
    ans[p] += d;
    w -= d;
  }
  if (w > 0) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
