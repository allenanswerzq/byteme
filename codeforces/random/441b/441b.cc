/*
 * created   : 2019-07-26 22:22:23
 * accepted  : 2019-07-26 23:14:30
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, v;
  cin >> n >> v;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  int ans = 0;
  int pr = 0;
  for (int i = 1; i <= 3001; i++) {
    int tot = 0;
    for (int j = 0; j < n; j++) {
      if (a[j].x == i) {
        tot += a[j].y;
      }
    }
    if (tot + pr <= v) {
      ans += tot + pr;
      pr = 0;
    }
    else {
      ans += v;
      int x = max(v - pr, 0);
      pr = tot - x;
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
