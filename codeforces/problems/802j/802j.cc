/* created   : 2019-11-03 11:46:52
 * accepted  : 2019-11-03 12:02:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 120;
vector<pair<int, int>> g[N];
int n;

int rec(int u, int pr = -1) {
  int mx = 0;
  for (auto it : g[u]) {
    if (it.x != pr) {
      mx = max(mx, rec(it.x, u) + it.y);
    }
  }
  return mx;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y, c; cin >> x >> y >> c;
    g[x].emplace_back(y, c);
    g[y].emplace_back(x, c);
  }
  cout << rec(0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
