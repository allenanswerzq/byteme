#include<bits/stdc++.h>using namespace std;

class Solution {
  // perfect it accepted
  int uniquePathsWithObstacles(vector<vector<int>>& aa) {
    int m = aa.size(), n = aa[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j) {
        if(!dp[i-1][j] && !dp[i][j-1])
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        else
          dp[i][j] = dp[i-1][j] == 1 ? 0: dp[i-1][j]
               + dp[i][j-1] == 1 ? 0: dp[i][j-1];
      } 
    return dp[m-1][n-1];
  }
};

int main() {
  return 0;
}
