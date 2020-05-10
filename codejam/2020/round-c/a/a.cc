/* created   : 2020-05-02 17:13:26
 * accepted  : 2020-05-02 17:42:21
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int x, y; cin >> x >> y;
  string s; cin >> s;
  vector<pair<pii, int>> a;
  int n = s.size();
  int time = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S') {
      y--;
    }
    else if (s[i] == 'N') {
      y++;
    }
    else if (s[i] == 'W') {
      x--;
    }
    else {
      x++;
    }
    a.push_back({{x, y}, ++time});
  }
  const int inf = 1e9 + 7;
  int mi = inf;
  for (auto it : a) {
    int xx = it.x.x;
    int yy = it.x.y;
    int t = it.y;
    if (abs(xx) + abs(yy) <= t) {
      mi = min(mi, t);
    }
  }
  trace(mi, a);
  if (mi == inf) {
    cout << "IMPOSSIBLE" << "\n";
  }
  else {
    cout << mi << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
