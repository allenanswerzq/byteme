#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  double knightProbability(int n, int k, int r, int c) {
  if (k == 0) return 1;
  // pre[i][j] denotes the probability when knight 
  // ends in [i][j] cell for each moves.
  double pre[n][n], cur[n][n];
  vpii dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
         {2, -1}, {1, -2}, {-1, -2}, {-2, -1}}; 
  mst(pre, 0);
  // The probability for the starting points is always 1.0 
  // when it ends moving.
  pre[r][c] = 1;
  while (k--) {
    mst(cur, 0);  
    fori (i, 0, n)
    fori (j, 0, n) {
      // Staring at this cell to make a new move.
      if (pre[i][j] > 0) {
      fora (dir, dirs) {
        int x = i + dir.fi, y = j + dir.se;
        if (0<=x && x<n && 0<=y && y<n)
        cur[x][y] += pre[i][j] / 8;
      }
      } 
    }
    memcpy(pre, cur, sizeof(cur));
  }

  double res = 0;
  fori (i, 0, n)
    fori (j, 0, n)
    res += pre[i][j];
  return res;
  }
};

void test(int n, int k, int r, int c) {
  Solution go;
  double res = go.knightProbability(n, k, r, c);
  cerr(res);    
}

int main() {
   test(3, 2, 0, 0);
  return 0;
}
