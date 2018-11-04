#include<bits/stdc++.h>
using namespace std;

class Solution {
  int uniquePathsWithObstacles(vector<vector<int>>& aa) {
    int m = aa.size(), n = aa[0].size();
    vector<vector<int>> dp(m, vector<int> (n, 0));
    // Below init part code can be improve
    dp[0][0] = aa[0][0]==0 ? 1:0;
    for (int i = 1; i < n; ++i) 
      if (dp[0][i-1]==0 || aa[0][i]==1) dp[0][i] = 0;
      else dp[0][i] = 1;
      
    for (int i = 1; i < m; ++i) 
      if (dp[i-1][0]==0 || aa[i][0]==1) dp[i][0] = 0;
      else dp[i][0] = 1;

    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j) {
        if (!aa[i][j])
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
      } 
    return dp[m-1][n-1];
  }
};

int main() {
  return 0;
}
