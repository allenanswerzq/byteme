/* created   : 2020-02-06 19:53:47
 * accepted  : 2020-02-06 22:40:09
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
  int n, m; cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].x >> a[i].y;
  }
  auto check = [&](int x) {
    int cnt_x = 0;
    for (int i = 0; i < m; i++) {
      if (a[i].x == x || a[i].y == x) {
        cnt_x++;
      }
    }
    vector<int> cnt(n + 1);
    for (int i = 1; i < m; i++) {
      bool equal_x = false;
      if (a[i].x == x || a[i].y == x) {
        equal_x = true;
      }
      if (!equal_x) {
        cnt[a[i].x]++;
        cnt[a[i].y]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (cnt[i] + cnt_x == m) {
        // trace(i, cnt, cnt_x);
        return true;
      }
    }
    return false;
  };
  bool ans = check(a[0].x);
  ans |= check(a[0].y);
  cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
