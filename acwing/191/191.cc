/* created   : 2020-06-29 08:13:09
 * accepted  : 2020-06-29 20:11:34
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

struct Node {
  int day, x, y, s0, s1, s2, s3;
};

const int N = 370;
bool use[N][4][4][7][7][7][7];
int a[N][4][4];

bool check_sunny(vector<vector<int>>& a, int x, int y) {
  assert(a.size() == 4 && a[0].size() == 4);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      assert(x + i < 4 && y + j < 4);
      if (a[x + i][y + j]) {
        return true;
      }
    }
  }
  return false;
}

int solve(int n) {
  memset(use, 0, sizeof(use));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        cin >> a[i][j][k];
      }
    }
  }
  if (check_sunny(a[0], 1, 1)) {
    return 0;
  }
  deque<Node> qu;
  qu.push_back({0, 1, 1, 1, 1, 1, 1});
  use[0][1][1][1][1][1][1] = true;
  vector<int> dx = {-1, 0, 1, 0, 0};
  vector<int> dy = {0, -1, 0, 1, 0};
  while (qu.size()) {
    auto cur = qu.front(); qu.pop_front();
    if (cur.day == n) {
      return 1;
    }
    trace(cur.day, cur.x, cur.y, cur.s0, cur.s1, cur.s2, cur.s3);
    for (int k = 0; k < 5; k++) {
      for (int step = 1; step <= 2; step++) {
        int x = cur.x + dx[k] * step;
        int y = cur.y + dy[k] * step;
        int s0 = cur.s0;
        int s1 = cur.s1;
        int s2 = cur.s2;
        int s3 = cur.s3;
        if (!(0 <= x && x < 3 && 0 <= y && y < 3)) continue;
        // If next day does not need to rain
        if (check_sunny(a[cur.day + 1], x, y)) continue;
        if (x == 0 && y == 0) s0 = 0; else if (++s0 == 7) continue;
        if (x == 0 && y == 2) s1 = 0; else if (++s1 == 7) continue;
        if (x == 2 && y == 0) s2 = 0; else if (++s2 == 7) continue;
        if (x == 2 && y == 2) s3 = 0; else if (++s3 == 7) continue;
        trace(cur.day + 1, x, y, s0, s1, s2, s3);
        if (use[cur.day+ 1][x][y][s0][s1][s2][s3]) continue;
        use[cur.day + 1][x][y][s0][s1][s2][s3] = true;
        qu.push_back({cur.day + 1, x, y, s0, s1, s2, s3});
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    cout << solve(n) << "\n";
  }
  return 0;
}
