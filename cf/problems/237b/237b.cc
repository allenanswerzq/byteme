/* created   : 2020-03-25 22:21:34
 * accepted  : 2020-03-25 23:07:31
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
#define xuyixuyi()
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

const int N = 55;
int a[N][N];
int f[N];

void solve() {
  int n; cin >> n;
  int s = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    s += x;
    f[i] = x;
  }
  map<int, pair<int, int>> mp;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= f[i]; j++) {
      cin >> a[i][j];
      mp[a[i][j]] = {i, j};
    }
  }
  auto it = mp.begin();
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= f[i]; j++) {
      if (a[i][j] != it->x) {
        ans.push_back({i, j});
        int x = it->y.x;
        int y = it->y.y;
        ans.push_back({x, y});
        mp[a[i][j]] = {x, y};
        mp[it->x] = {i, j};
        swap(a[i][j], a[x][y]);
      }
      it++;
    }
  }
  trace(mt(a, 10, 10));
  int m = ans.size();
  cout << m / 2 << '\n';
  assert(m / 2 <= s);
  for (int i = 0; i + 1 < m; i += 2) {
    cout << ans[i].x << ' ' << ans[i].y << ' '
         << ans[i + 1].x << ' ' << ans[i + 1].y << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
