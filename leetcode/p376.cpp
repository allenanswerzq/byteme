#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int wiggleMaxLength(vector<int>& aa) {
    int n, res;
    n = sz(aa);
    if (n <= 1) return n;
    int dp[n][2];
    fori(i, 0, n) dp[i][0] = dp[i][1] = 1;
    res = 0;
    fori (i, 1, n) {
      fori (j, 0, i) {
        if (aa[j] < aa[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        if (aa[j] > aa[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
      }
      res = max(res, dp[i][0]);
      res = max(res, dp[i][1]);
    }
    return res;
  }
};

void test(vi aa) {
  Solution go;
  cout << go.wiggleMaxLength(aa) << "\n";
}

int main() {
  test({1, 7, 4, 9, 2, 5});
  test({0, 0});
  return 0;
}
