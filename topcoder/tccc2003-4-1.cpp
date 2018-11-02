#include<bits/stdc++.h>
using namespace std;

class ChessMetric {
public:
  ll dp[120][120][60];
  ll howMany(int size, vi start, vi end, int numMoves) {
    mst(dp, 0);
    vector<vi> dirs = {{0, 1}, {0, -1}, {1,0}, {-1, 0},
                       {1, 1}, {-1, -1  }, {1, -1}, {-1, 1},
                       {-2, 1}, {-2, -1}, {2, 1}, {2, -1},
                       {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    dp[start[0]][start[1]][0] = 1;
    fori (move, 1, numMoves+1) {
      fori (i, 0, size)
        fori (j, 0, size) {
          fora(dir, dirs) {
            int nx = i+dir[0], ny = j+dir[1];
            if (0<=nx && nx<size && 0<=ny && ny<size)
              dp[i][j][move] += dp[nx][ny][move-1];
          }
        }
    }
    return dp[end[0]][end[1]][numMoves];
  }
};

void test(int aa, vi bb, vi cc, int dd) {
  ChessMetric go;
  auto r = go.howMany(aa, bb, cc, dd);
  output(r);
}

int main() {
  test(3, {0,0}, {1,0}, 1);
  test(3, {0,0}, {0,0}, 2);
  test(100, {0,0}, {0,99}, 50);
  return 0;
}
