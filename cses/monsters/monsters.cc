/* created   : 2020-11-15 10:53:43
 * accepted  : 2020-11-16 21:46:52
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  const int INF = 1234;
  vector<vector<int>> dist(N, vector<int>(M, -INF));
  deque<array<int, 2>> me;
  vector<vector<int>> distm(N, vector<int>(M, -INF));
  deque<array<int, 2>> monster;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (S[i][j] == 'A') {
        me.push_back({i, j});
        dist[i][j] = 0;
      }
      else if (S[i][j] == 'M') {
        monster.push_back({i, j});
        distm[i][j] = 0;
      }
    }
  }
  trace(me, monster);
  vector<int> dx = {0, 0, -1, 1};
  vector<int> dy = {-1, 1, 0, 0};
  int gx = -1, gy = -1;
  while (me.size() || monster.size()) {
    if (monster.size()) {
      int x = monster.front()[0];
      int y = monster.front()[1];
      monster.pop_front();
      trace("monster", x, y);
      for (int k = 0; k < 4; k++) {
        size_t xx = x + dx[k];
        size_t yy = y + dy[k];
        if (xx < N && yy < M && S[xx][yy] != '#' && distm[xx][yy] <= 0) {
          distm[xx][yy] = distm[x][y] + 1;
          monster.push_back({xx, yy});
        }
      }
    }
    if (me.size()) {
      int x = me.front()[0];
      int y = me.front()[1];
      me.pop_front();
      trace("me", x, y);
      if (x == 0 || x == N - 1 || y == 0 || y == M - 1) {
        gx = x, gy = y;
        break;
      }
      for (int k = 0; k < 4; k++) {
        size_t xx = x + dx[k];
        size_t yy = y + dy[k];
        if (xx < N && yy < M && S[xx][yy] == '.' && dist[xx][yy] == -INF) {
          if (dist[x][y] + 1 != distm[xx][yy]) {
            dist[xx][yy] = dist[x][y] + 1;
            me.push_back({xx, yy});
          }
        }
      }
    }
  }
  if (gx == -1) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    string ans;
    trace(gx, gy, dist, distm);
    while (dist[gx][gy] > 0) {
      if (gx && dist[gx - 1][gy] + 1 == dist[gx][gy]) {
        gx--;
        ans += 'D';
      }
      else if (gy && dist[gx][gy - 1] + 1 == dist[gx][gy]) {
        gy--;
        ans += 'R';
      }
      else if (gx + 1 < N && dist[gx + 1][gy] + 1 == dist[gx][gy]) {
        gx++;
        ans += 'U';
      }
      else if (gy + 1 < M && dist[gx][gy + 1] + 1 == dist[gx][gy]) {
        gy++;
        ans += 'L';
      }
      else {
        trace(gx, gy, dist[gx][gy + 1]);
        assert(false);
      }
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
