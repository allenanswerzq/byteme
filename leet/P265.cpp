#include<bits/stdc++.h>
using namespace std;

// There are a row of n houses, each house can be painted with one of the k colors. 
// The cost of painting each house with a certain color is different. 
// You have to paint all the houses such that no two adjacent houses have the same color.
// The cost of painting each house with a certain color is represented by a n x k cost matrix. 
// For example, costs[0][0] is the cost of painting house 0 with color 0; 
// costs[1][2] is the cost of painting house 1 with color 2, 
// and so on... Find the minimum cost to paint all houses.

int minCostII(vector<vector<int>>& costs) {
  int n = costs.size();
  int m = costs[0].size();
  int ret = (1<<31) - 1;
  int dp[n + 1][m];
  mst(dp, 0);
  // For each house
  for (int i=1; i<=n; ++i) {  
  // For each color
  for (int j=0; j<m; ++j) { 
  int pre = (1<<31) - 1;
  for (int k=0; k<m; ++k)
  if (k != j) pre = min(pre, dp[i-1][k]);

  dp[i][j] = costs[i-1][j] + pre;
  ret = min(ret, dp[i][j]);
  }
  }
  return ret;
}

int minCostII(vector<vector<int>>& costs) {
  if (costs.empty()) return 0;
  int n = costs.size(), k = costs[0].size();
  // m1 min value, m2 second min value
  int m1 = 0, m2 = 0;           
  vector<int> dp(k, 0);
  // Paint each house
  for (int i = 0; i < n; i++) { 
  // The previous minimum cost and the previous second minimum cost.
  int t1 = m1, t2 = m2;
  m1 = m2 = (1<<31) - 1;
  // Pick each color
  for (int j = 0; j < k; j++) { 
  // If last time we got min costs on color j for painting house i-1, 
  // now when we pick color j, we can only use second min costs of last time
  // because two adjcent house have different colors
  int pre = dp[j] == t1 ? t2 : t1;  
  dp[j] = pre + costs[i][j];

  if (dp[j] > m1) m2 = min(m2, dp[j]);
  else m2 = m1, m1 = dp[j];
  }
  }
  return m1;
}

int main(int argc, char** argv) {
  return 0;
}
