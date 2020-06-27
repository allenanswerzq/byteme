/* created   : 2020-06-27 17:58:04
 * accepted  : 2020-06-27 18:15:33
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n, m, h, w; cin >> m >> n >> w >> h;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    assert(a[i].size() == m);
  }
  h--, w--;
  vector<vector<bool>> use(n, vector<bool>(m));
  deque<pair<int, int>> qu;
  qu.push_back({h, w});
  int step = 0;
  vector<int> dx = {-1, -1, -1, 1, 1, 1, 0, 0};
  vector<int> dy = {-1, 0, 1, -1, 0, 1, 1, -1};
  while (qu.size()) {
    int sz = qu.size();
    bool ok = false;
    for (int i = 0; i < sz; i++) {
      auto tp = qu.front(); qu.pop_front();
      int x = tp.x, y = tp.y;
      for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
        // trace(n, m, nx, ny);
        if (a[nx][ny] == '*') continue;
        if (use[nx][ny]) continue;
        use[nx][ny] = true;
        qu.push_back({nx, ny});
        ok = true;
      }
    }
    if (!ok) {
      cout << step << "\n";
      return;
    }
    step++;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
    return 0;
}
