/* created   : 2020-06-24 08:15:37
 * accepted  : 2020-06-24 08:49:53
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int INF = 1200;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
  int n, m; cin >> n >> m;
  vector<string> a(n);
  deque<pair<int, int>> qu;
  vector<vector<int>> ans(n, vector<int>(m, INF));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1') {
        qu.push_back({i, j});
        ans[i][j] = 0;
      }
    }
  }
  while (qu.size()) {
    auto t = qu.front(); qu.pop_front();
    for (int k = 0; k < 4; k++) {
      int x = dx[k] + t.x;
      int y = dy[k] + t.y;
      if (!(0 <= x && x < n && 0 <= y && y < m)) continue;
      if (a[x][y] != '0') continue;
      if (ans[x][y] == INF) {
        ans[x][y] = ans[t.x][t.y] + 1;
        qu.push_back({x, y});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << (j == m - 1 ? '\n' : ' ');
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
