#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
  int n = cost.size();
  // dp[i] denotes total cost for reaching ith postion,
  // so dp[n] is the result we wanted
  vector<int> dp(n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
  }
  return dp[n];
}
