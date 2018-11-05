#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int combinationSum4(vector<int>& aa, int goal) {
    int dp[goal+1];
    mst(dp, 0);
    dp[0] = 1;
    fori (i, 1, goal+1) {
      fora (c, aa) {
        if (i >= c) dp[i] += dp[i - c];
      }
    }
    par(dp, goal+1);
    return dp[goal];
  }
};

void test(vi aa, int n) {
  Solution go;
  cout << go.combinationSum4(aa, n) << "\n";
}

int main() {
  test({1, 2, 3}, 4);
  return 0;
}
