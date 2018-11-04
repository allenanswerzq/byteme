#include<bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  int numTrees(int n) {
    int dp[n + 1]; mst(dp, 0);
    dp[0] = 1;
    dp[1] = 1;
    fori (i, 2, n + 1) {
      fori (j, 0, i) {
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }
    return dp[n];
  }
};

int main() {
   return 0;
}
