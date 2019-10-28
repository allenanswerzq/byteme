/* created   : 2019-10-27 16:58:38
 * accepted  : 2019-10-27 17:51:52
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

const int N = 20;
vector<string> g[N];
bool use[N][N][N];
int k;
int n;
int m;
int ans;

bool check(int h, int x, int y) {
  int ret = 1;
  ret &= (0 <= h && h < k);
  ret &= (0 <= x && x < n);
  ret &= (0 <= y && y < m);
  // ret &= (lh <= h);
  return ret;
}

void dfs(int h, int x, int y) {
  vector<vector<int>> dirs = {
    {0, 0, 1},
    {0, 0, -1},
    {0, 1, 0},
    {0, -1, 0},
    {1, 0, 0},
    {-1,0, 0}
  };
  ans++;
  use[h][x][y] = 1;
  // trace(h, x, y, ans);
  for (auto d : dirs) {
    int nh = h + d[0];
    int nx = x + d[1];
    int ny = y + d[2];
    if (check(nh, nx, ny) && !use[nh][nx][ny] && g[nh][nx][ny] == '.') {
      dfs(nh, nx, ny);
    }
  }
}

void solve() {
  cin >> k >> n >> m;
  trace(k, n, m);
  for (int i = 0; i < k; i++) {
    string x; getline(cin, x);
    for (int j = 0; j < n; j++) {
      cin >> x;
      g[i].push_back(x);
    }
  }
  trace(mt(g, k));
  int x, y; cin >> x >> y;
  trace(x, y);
  x--;
  y--;
  dfs(0, x, y);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
ssssssssss
sssssssss
