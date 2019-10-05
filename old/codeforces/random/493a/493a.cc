/*
 * created   : 2019-07-23 23:44:23
 * accepted  : 2019-07-23 23:57:07
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
  vector<string> a(2);
  cin >> a[0] >> a[1];
  string team = "ha";
  trace(a);
  vector<vector<int>> cnt(2, vector<int>(120));
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t;
    char c;
    int x;
    char y;
    cin >> t >> c >> x >> y;
    int ix = team.find(c);
    trace(t, c, x, y, ix);
    if ((y == 'r' && cnt[ix][x] != -1) || cnt[ix][x] > 0) {
      cout << a[ix] << " " << x << " " << t << "\n";
      cnt[ix][x] = -1;
    }
    if (y == 'y' && cnt[ix][x] != -1) {
      cnt[ix][x] = t;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
