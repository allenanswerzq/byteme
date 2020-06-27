/* created   : 2020-06-27 17:42:41
 * accepted  : 2020-06-27 17:53:23
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n, m; cin >> m >> n;
  vector<string> a(n);
  pair<int, int> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'K') {
        p = {i, j};
      }
    }
  }
  deque<array<int, 3>> qu;
  vector<vector<bool>> use(n, vector<bool>(m));
  qu.push_back({p.x, p.y, 0});
  use[p.x][p.y] = true;
  vector<int> dx = {-1, -1, 1, 1, 2, 2, -2, -2};
  vector<int> dy = {2, -2, 2, -2, -1, 1, 1, -1};
  while (qu.size()) {
    auto tp = qu.front(); qu.pop_front();
    int x = tp[0];
    int y = tp[1];
    int d = tp[2];
    if (a[x][y] == 'H') {
      cout << d << "\n";
      return;
    }
    for (int k = 0; k < 8; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
      if (a[nx][ny] == '*') continue;
      if (use[nx][ny]) continue;
      use[nx][ny] = true;
      qu.push_back({nx, ny, d + 1});
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
