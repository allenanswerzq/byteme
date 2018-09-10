#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    int dp[n + 1];
    int a, b, c;
    mst(dp, 0); 
    dp[1] = 1;
    a = b = c = 1; 
    fori (i, 2, n + 1) {
      int cur = dp[i-1];
      while (dp[a] * 2 <= cur) ++a;
      while (dp[b] * 3 <= cur) ++b;
      while (dp[c] * 5 <= cur) ++c;
      dp[i] = min(dp[a] * 2, min(dp[b] * 3, dp[c] * 5));
    }    
    return dp[n];
  }
  
  int nthUglyNumber(int n) {
    vector<int> ugly(n, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; ++i) {
      int cur_max = ugly[i-1];
      while (ugly[i2] * 2 <= cur_max) i2++;
      while (ugly[i3] * 3 <= cur_max) i3++;
      while (ugly[i5] * 5 <= cur_max) i5++;
      ugly[i] = min(min(ugly[i2] * 2, ugly[i3] * 3), ugly[i5] * 5);
    }
    return ugly[n - 1];
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
