#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int integerBreak(int n) {
    int dp[n+1];
    mst(dp, 0);
    dp[1] = 1; dp[2] = 1;
    fori (i, 3, n+1) {
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

void test(int n) {
  Solution go;
  cout << go.integerBreak(n) << "\n";
}

int main() {

  test(5);
  test(3);
  test(2);
  test(10);
  test(58);

  return 0;
}
