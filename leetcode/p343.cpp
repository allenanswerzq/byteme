#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int integerBreak(int n) {
  int dp[n+1];
  mst(dp, 0);
  dp[1] = 1;
  dp[2] = 1;
  fori(i, 3, n+1) {
    int mx = 0;
    fori(j, 1, i) {
    mx = max(mx, dp[i - j] * j);
    mx = max(mx, (i-j) * j);
    }
    dp[i] = mx;
  }       

  // fori(i, 0, n+1)
  //   cout << dp[i] << " ";
  // cout << "\n";

  return dp[n];
  }
};

void TEST(int n) {
  Solution go;
  cout << go.integerBreak(n) << "\n";
}

int main() {
 
  TEST(5);
  TEST(3);
  TEST(2);
  TEST(10);
  TEST(58);

  return 0;
}
