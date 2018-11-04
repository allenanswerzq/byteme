#include<bits/stdc++.h>
using namespace std;

int dp[32][32][1 << 6];
vvi dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vs grid;
int m, n;

class Solution {
public:

  int go(int sr, int sc) {
    int keys = 0;
    fori (i, 0, m)
      fori (j, 0, n) {
        if ('a'<=grid[i][j] && grid[i][j]<='z') {
          keys |= 1 << (grid[i][j] - 'a');
        }
      }

    mst(dp, -1);
    dp[sr][sc][0] = 0;
    deque<int> dq;
    dq.pb((sr << 12) + (sc << 6) + 0);
    while (sz(dq)) {
      int status = dq.fr(); dq.ppf();
      int r = status >> 12;
      int c = (status >> 6) & 0x3f;
      int k = (status) & 0x3f;
      // trace(r, c, k, keys);
      fori (i, 0, 4) {
        int nr = r + dirs[i][0];
        int nc = c + dirs[i][1];
        if (!(0<=nr && nr<m && 0<=nc && nc<n)) continue;
        char ch = grid[nr][nc];
        if (ch == '#') continue;
        if ('A' <= ch && ch <= 'Z') {
          int x = 1 << (ch - 'A');
          if (!(k & x)) continue;
        }
        int nk = k;
        if ('a' <= ch && ch <= 'z') nk |= 1 << (ch - 'a');
        // trace(nr, nc, nk);
        if (dp[nr][nc][nk] < 0) {
          dp[nr][nc][nk] = dp[r][c][k] + 1;
          if (nk == keys) return dp[nr][nc][nk];
          dq.pb((nr << 12) + (nc << 6) + nk);
        }
      }
    }
    return -1;
  }

  int shortestPathAllKeys(vector<string>& g) {
    grid = g;
    m = sz(grid);
    if (m < 1) return -1;
    n = sz(grid[0]);
    fori (i, 0, m) {
      fori (j, 0, n)
        if (grid[i][j] == '@')
          return go(i, j);
    }
    return -1;
  }
};

int main() {
  return 0;
}
