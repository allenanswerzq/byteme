#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int aa) {
  int n = aa;
  int dp[n+1];
  mst(dp, -1);
  dp[0] = 0;

  fori(i, 1, n+1) {
    int mi = 0x3f3f3f3f;
    fora(c, coins)
    if (i - c >= 0 && dp[i - c] != -1)
      mi = min(mi, dp[i-c] + 1);
    dp[i] = mi == 0x3f3f3f3f ? -1 : mi;
  } 

  // fori(i, 0, n+1)
  //   cout << dp[i] << " ";
  // cout << "\n";

  return dp[n];
  }
};

void TEST(vi aa, int n) {
  Solution go;
  cout << go.coinChange(aa, n) << "\n";
}

int main() {
   
  TEST({1,2,5}, 11);
  TEST({2}, 3);

  return 0;
}
