#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& aa) {
    int n, res;
    int dp[n + 1];
    n = sz(aa);
    if (n < 3) return 0;
    mst(dp, 0);
    if (aa[2] - aa[1] == aa[1] - aa[0]) dp[2] = 1;
    res = dp[2];
    fori (i, 3, n) {
      if (aa[i] - aa[i-1] == aa[i-1] - aa[i-2]) dp[i] = dp[i-1] + 1;
      res += dp[i];
    }
    par(dp, n);
    return res;
  }
};

void test(vi aa) {
  Solution go;
  int r = go.numberOfArithmeticSlices(aa);
  output(r);
}

int main() {
  test({1, 2, 3, 8, 9, 10});
  test({1, 2, 3, 4});
  test({1, 3, 5, 7, 9});
  return 0;
}
