#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rob(vector<int>& aa) {
    int n = aa.size();
    if (n <= 0) return 0;
    if (n == 1) return aa[0];
    vector<int> dp(n, 0);
    dp[0] = aa[0];
    dp[1] = max(aa[0], aa[1]);
    for (int i = 2; i < n; ++i) {
      dp[i] = max(dp[i-1], dp[i-2] + aa[i]);
    }
    return dp[n-1];
  }
};

int main() {
  return 0;
}
