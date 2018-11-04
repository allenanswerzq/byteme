#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>>& aa) {
    int n = sz(aa);
    int dp[n][n]; mst(dp, 0x3f);

    fori (i, 0, n) 
      fori (j, 0, sz(aa[i])) {
        if (i == 0) 
          dp[i][j] = aa[i][j];
        else {
          dp[i][j] = dp[i-1][j] + aa[i][j];
          if (j >= 1) 
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + aa[i][j]);
        }
      }

    int res = 0x3f3f3f3f; 
    fori (i, 0, n) 
      res = min(res, dp[n-1][i]);
    return res;
  }
};

int main() {
   return 0;
}
