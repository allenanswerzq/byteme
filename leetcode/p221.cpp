#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define mst(x, a) memset(x, a, sizeof(x))
#define fori(i, a, b) for(int i=(a); i<(b); ++i)

class Solution {
public:
  int maximalSquare(vector<vector<char>>& aa) {
  if (sz(aa) <= 0) return 0;
  int n, m;
  n = sz(aa);
  m = sz(aa[0]); 

  int dp[n][m]; mst(dp, 0);

  int res = 0;
  fori (i, 0, n) {
    fori (j, 0, m) {
      if (i == 0)
        dp[i][j] = aa[i][j] - '0';
      else if (j == 0)
        dp[i][j] = aa[i][j] - '0';
      else if (aa[i][j] == '1') {
        dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
      }
    }
  }

  fori (i, 0, n) 
    fori (j, 0, m)
    res = max(res, dp[i][j] * dp[i][j]);
  return res;
  }
};

void test(vvi aa) {
  Solution go;
  cout << go.maximalSquare(aa) << "\n"; 
}

int main() {
   vvi aa = {{1,0,1,0,0},
      {1,0,1,1,1}, 
      {1,1,1,1,1},
      {1,0,0,1,0}};
  test(aa); 
  return 0;
}
