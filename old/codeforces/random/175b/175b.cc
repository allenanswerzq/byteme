/* created   : 2019-08-28 23:29:29
 * accepted  : 2019-08-29 00:15:27
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
  int n; cin >> n;
  vector<pair<string, int>> a;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string x; int y; cin >> x >> y;
    if (mp.count(x)) {
      a[mp[x]].y = max(a[mp[x]].y, y);
    }
    else {
      mp[x] = (int) a.size();
      a.push_back(make_pair(x, y));
    }
  }
  n = (int) a.size();
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    int lose = 0;
    for (int j = 0; j < n; j++) {
      if (a[j].y <= a[i].y) {
        lose++;
      }
    }
    string ans;
    if (lose * 100 >= n * 99) {
      ans = "pro";
    }
    else if (lose * 100 >= n * 90) {
      ans = "hardcore";
    }
    else if (lose * 100 >= n * 80) {
      ans = "average";
    }
    else if (lose * 100 >= n * 50) {
      ans = "random";
    }
    else {
      ans = "noob";
    }
    trace(a[i], lose, ans);
    cout << a[i].x << ' ' << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
