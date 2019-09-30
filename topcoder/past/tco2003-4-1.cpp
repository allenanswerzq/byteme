#include<bits/stdc++.h>
using namespace std;

// Still not work, dont want to waste too much time on this problem now.
class AvoidRoads {
public:
  ll grid[120][120];
  ll dp[120][120];
  ll numWays(int height, int width, vs bad) {
    mst(dp, 0);
    mst(grid, 0);
    ++height; ++width;
    int w = 1;
    fora (s, bad) {
      istringstream iss(s);
      int a, b, c, d;
      iss >> a >> b >> c >> d;
      if (grid[a][b] && !grid[c][d]) {
        grid[c][d] = grid[a][b];
      } else if (grid[c][d] && !grid[a][b]) {
        grid[a][b] = grid[c][d];
      } else if (grid[a][b] && grid[c][d] && grid[a][b] != grid[c][d]) {
        int t = grid[a][b];
        int old = grid[c][d];
        vector<vi> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};
        grid[c][d] = t;

        deque<pii> dq;
        dq.pb(pii(c, d));
        while (!dq.empty()) {
          int x = dq.front().fi, y = dq.front().se; dq.pf();
          fora (dir, dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if (0 <= nx && nx <= height && 0 <= ny && ny <= width &&
                grid[nx][ny] == old) {
              grid[nx][ny] = t;
              dq.pb(pii(nx, ny));
            }
          }
        }
      } else if (grid[a][b] && grid[c][d] && grid[a][b] == grid[c][d]) {

      } else {
        grid[a][b] = w;
        grid[c][d] = w;
        w++;
      }
    }

    dp[0][0] = 1;
    fori (i, 0, height) {
      fori (j, 0, width) {

        if (i > 0) {
          if (grid[i-1][j] && grid[i][j] && grid[i-1][j] == grid[i][j]) {
            dp[i][j] += 0;
          } else {
            dp[i][j] += dp[i-1][j];
          }
        }

        if (j > 0) {
          if (grid[i][j-1] && grid[i][j] && grid[i][j-1] == grid[i][j]) {
            dp[i][j] += 0;
          } else {
            dp[i][j] += dp[i][j-1];
          }
        }
      }
    }
    return dp[height - 1][width - 1];
  }
};

void test(int a, int b, vi c) {
  AvoidRoads go;
  auto r = go.numWays(a, b, c);
  output(r);
}

int main() {
  test(6, 6, {"0 0 0 1","6 6 5 6"});
  test(24, 24, {"0 0 0 1", "0 0 1 0", "0 1 0 0"});
  return 0;
}
