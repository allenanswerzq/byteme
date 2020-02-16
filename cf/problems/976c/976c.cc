/* created   : 2020-02-16 11:41:50
 * accepted  : 2020-02-16 12:17:27
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

#define pii pair<int, int>
#define ppii pair<pii, int>

void solve() {
  int n; cin >> n;
  vector<ppii> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].x.x >> v[i].x.y;
    v[i].y = i + 1;
  }
  trace(v);
  sort(all(v), [](const ppii& a, const ppii& b) {
    if (a.x.x != b.x.x) {
      return a.x.x < b.x.x;
    }
    else {
      return a.x.y > b.x.y;
    }
  });
  set<pii> right;
  for (int i = 0; i < n; i++) {
    int cur = v[i].x.y;
    trace(cur, right);
    auto it = right.lower_bound({cur, -1});
    if (it != right.end()) {
      cout << v[i].y << ' ' << (*it).y << '\n';
      return;
    }
    // insert the right position and the index of current segment
    right.insert({v[i].x.y, v[i].y});
  }
  cout << -1 << ' ' << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
