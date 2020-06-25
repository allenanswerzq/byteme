/* created   : 2020-06-25 08:00:06
 * accepted  : 2020-06-25 11:42:26
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n, m; cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int INF = 1e9 + 7;
  vector<vector<int>> dist(n + 1, vector<int>(m + 1, INF));
  vector<vector<bool>> use(n + 1, vector<bool>(m + 1));
  vector<int> dx = {-1, -1, 1, 1};
  vector<int> dy = {-1, 1, 1, -1};
  vector<int> ix = {-1, -1, 0, 0};
  vector<int> iy = {-1, 0, 0, -1};
  string chs = "\\/\\/";
  deque<pair<int, int>> qu;
  qu.push_back({0, 0});
  dist[0][0] = 0;
  while (qu.size()) {
    auto t = qu.front(); qu.pop_front();
    int x = t.x, y = t.y;
    if (use[x][y]) continue;
    use[x][y] = true;
    for (int k = 0; k < 4; k++) {
      int nx = dx[k] + x;
      int ny = dy[k] + y;
      if (!(0 <= nx && nx <= n && 0 <= ny && ny <= m)) continue;
      int w = (a[x + ix[k]][y + iy[k]] != chs[k]);
      if (dist[nx][ny] > dist[x][y] + w) {
        dist[nx][ny] = dist[x][y] + w;
        if (w) {
          qu.push_back({nx, ny});
        }
        else {
          qu.push_front({nx, ny});
        }
      }
    }
  }
  if (dist[n][m] == INF) {
    cout << "NO SOLUTION\n";
  }
  else {
    cout << dist[n][m] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
