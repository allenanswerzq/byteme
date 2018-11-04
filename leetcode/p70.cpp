#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int dp[n + 1];
    mst(dp, 0);
    dp[0] = 1; 
    dp[1] = 1;
    fori (i, 2, n+1)
      dp[i] = dp[i-1] + dp[i-2];
    return dp[n];    
  }

  int climbStairs2(int n) {
    int a = 1, b = 2, c;
    if (n == 1) return a;
    if (n == 2) return b;
    for (int i = 2; i < n; ++i) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;    
  }
};

int main() {
   return 0;
}
