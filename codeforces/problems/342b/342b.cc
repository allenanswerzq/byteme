/* created   : 2020-03-15 23:09:58
 * accepted  : 2020-03-15 23:48:01
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
typedef pair<int, int> pii;

void solve() {
  int n, m, s, f;
  cin >> n >> m >> s >> f;
  map<int, pii> mp;
  for (int i = 0; i < m; i++) {
    int t, l, r; cin >> t >> l >> r;
    mp[t] = {l, r};
  }
  trace(mp);
  string ans;
  if (s < f) {
    for (int step = 1; ; step++) {
      if (s == f) {
        break;
      }
      if (!mp.count(step)) {
        trace(step, s);
        s++;
        ans += "R";
      }
      else {
        auto p = mp[step];
        if (p.x <= s && s <= p.y) {
          ans += "X";
        }
        else if (p.x <= s + 1 && s + 1 <= p.y) {
          ans += "X";
        }
        else {
          trace(step, p, s);
          ans += 'R';
          s++;
        }
      }
    }
  }
  else if (s > f) {
    trace(s, f);
    for (int step = 1; ; step++) {
      if (s == f) {
        break;
      }
      if (!mp.count(step)) {
        s--;
        ans += "L";
      }
      else {
        auto p = mp[step];
        if (p.x <= s && s <= p.y) {
          ans += "X";
        }
        else if (p.x <= s - 1 && s - 1 <= p.y) {
          ans += "X";
        }
        else {
          ans += 'L';
          s--;
        }
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
