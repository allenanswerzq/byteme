/* created   : 2020-06-25 16:52:04
 * accepted  : 2020-06-25 18:05:34
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int solve() {
  int n, m; cin >> n >> m;
  vector<string> a(n);
  vector<pair<int, int>> ghost;
  pair<int, int> b, g;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'M') {
        b = {i, j};
      }
      else if (a[i][j] == 'G') {
        g = {i, j};
      }
      else if (a[i][j] == 'Z') {
        ghost.push_back({i, j});
      }
    }
  }
  auto die = [&](int x, int y, int d) {
    for (auto gh : ghost) {
      if (abs(gh.x - x) + abs(gh.y - y) <= 2 * d) {
        return true;
      }
    }
    return false;
  };
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  vector<vector<int>> vis(n, vector<int>(m));
  deque<pair<int, int>> boy, girl;
  boy.push_back(b);
  vis[b.x][b.y] = 1;
  girl.push_back(g);
  vis[g.x][g.y] = 2;
  int step = 0;
  while (boy.size() || girl.size()) {
    step++;
    for (int i = 0; i < 3; i++) {
      int nb = boy.size();
      for (int j = 0; j < nb; j++) {
        auto t = boy.front(); boy.pop_front();
        int x = t.x, y = t.y;
        if (die(x, y, step)) continue;
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
          if (vis[nx][ny] == 1) continue;
          if (a[nx][ny] == 'X' || a[nx][ny] == 'Z') continue;
          if (vis[nx][ny] == 2) return step;
          vis[nx][ny] = 1;
          boy.push_back({nx, ny});
        }
      }
    }
    for (int i = 0; i < 1; i++) {
      int ng = girl.size();
      for (int j = 0; j < ng; j++) {
        auto t = girl.front(); girl.pop_front();
        int x = t.x, y = t.y;
        if (die(x, y, step)) continue;
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
          if (vis[nx][ny] == 2) continue;
          if (a[nx][ny] == 'X' || a[nx][ny] == 'Z') continue;
          if (vis[nx][ny] == 1) return step;
          vis[nx][ny] = 2;
          girl.push_back({nx, ny});
        }
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    int r = solve();
    cout << r << "\n";
  }
  return 0;
}
