/* created   : 2020-11-14 10:18:50
 * accepted  : 2020-11-14 16:19:23
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<string> S(N);
  for (string& s : S) {
    cin >> s;
  }
  int ax = -1, ay = -1;
  int bx = -1, by = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (S[i][j] == 'B') {
        bx = i, by = j;
      }
      else if (S[i][j] == 'A') {
        ax = i, ay = j;
      }
    }
  }
  const int INF = 1e9;
  vector<vector<int>> dist(N, vector<int>(M, INF));
  deque<array<int, 2>> qu;
  qu.push_back({ax, ay});
  dist[ax][ay] = 0;
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  while (qu.size()) {
    int x = qu.front()[0];
    int y = qu.front()[1];
    qu.pop_front();
    trace(x, y, qu);
    // S[x][y] = '#';
    for (int k = 0; k < 4; k++) {
      size_t xx = x + dx[k];
      size_t yy = y + dy[k];
      if (xx < N && yy < M && S[xx][yy] != '#'&& dist[xx][yy] == INF) {
        trace(x, y, xx, yy);
        dist[xx][yy] = dist[x][y] + 1;
        qu.push_back({xx, yy});
      }
    }
  }
  if (dist[bx][by] != INF) {
    string ans;
    while (dist[bx][by]) {
      if (bx && dist[bx - 1][by] + 1 == dist[bx][by]) {
        bx--;
        ans += 'D';
      }
      else if (by && dist[bx][by - 1] + 1 == dist[bx][by]) {
        by--;
        ans += 'R';
      }
      else if (bx + 1 < N && dist[bx + 1][by] + 1 == dist[bx][by]) {
        bx++;
        ans += 'U';
      }
      else if (by + 1 < M && dist[bx][by + 1] + 1 == dist[bx][by]) {
        by++;
        ans += 'L';
      }
    }
    reverse(all(ans));
    cout << "YES\n";
    cout << ans.size() << "\n";
    cout << ans << "\n";
  }
  else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
