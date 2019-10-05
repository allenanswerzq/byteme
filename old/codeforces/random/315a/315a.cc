/*
 * created   : 2019-07-27 23:47:02
 * accepted  : 2019-07-28 00:18:42
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
  int n;
  cin >> n;
  vector<int> cnt(1200);
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    cnt[a[i].y]++;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[a[i].x] == 0 || (cnt[a[i].x] == 1 && a[i].x == a[i].y)) {
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
