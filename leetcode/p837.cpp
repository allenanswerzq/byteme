#include <bits/stdc++.h>
using namespace std;


// TODO
// dp[i] denotes the probability of getting `i` points
// dp[i] = dp[i-1] + (1 point for ith draw with prob 1 / w).
//         dp[i-2] + (2 points for ith draw with prob 1 / w).
//         dp[i-3] + (3 points for ith draw with prob 1 / w).
//         ....
//         dp[i-w] + (w points for ith draw with prob 1 / w).
// Namely:
// dp[i] = dp[i-1] * 1/w + dp[i-2] * 1/w + ... + dp[i-w] * 1/w
// The result will be sum(dp[j]) where k <= j <= n

class Solution {
public:
  // Can not pass the last test.
  // But can easily understanded by me.
  double new21Game(int n, int k, int w) {
    // Speical case 1: k equals 0
    if (k == 0) return 1.0;
    // Speical case 2: maximum points we can get through
    // this game is `k - 1 + w`.
    if (n >= k - 1 + w) return 1.0;

    vector<double> dp(n + 1);
    dp[0] = 1.0;

    fori(i, 1, n + 1) {
      if (i < k) {
        double sum = 0;
        for (int j=i-1; j >= i-w && j>=0; j--) sum += dp[j];
        dp[i] = sum / w;
      } else {
        // Game already ended.
        double sum = 0;
        for(int j=k-1; j >= i-w && j>=0; j--)
          sum += dp[j];
        dp[i] = sum / w;
      }
    }

    // par(dp, n + 1);

    double res = 0;
    fori (i, k, n + 1) {
      res += dp[i];
    }

    return res;
  }

  double new21Game(int n, int k, int w) {
    if (k == 0) return 1.0;
    if (n >= k + w - 1) return 1.0;
    vector<double> dp(n + 1);
    double res, sum;
    res = 0;
    sum = 1.0;
    dp[0] = 1.0;
    fori (i, 1, n) {
      dp[i] = sum / w;
      if (i < k) sum += dp[i];
      else res += dp[i];
      if (i >= w) sum -= dp[i - w];
    }
    return res;
  }
};

void test(int n, int k, int w) {
  Solution go;
  double r = go.new21Game(n, k, w);
  output(r);
}

int main() {
  test(6, 1, 10);
  test(21, 17, 10);
  test(5819, 5165, 5424);
  return 0;
}
