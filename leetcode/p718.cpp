#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  int findLength(vector<int>& aa, vector<int>& bb) {
    int m, n, mx;
    m = sz(aa), n = sz(bb);
    // dp[i][j] denotes the length of the longest subarray ending
    // at the `ith` and the `jth` position.
    int dp[m + 1][n + 1];
    mst(dp, 0);
    mx = 0;
    fori (i, 0, m + 1) fori (j, 0, n + 1) {
      if (i == 0 || j == 0) dp[i][j] = 0;
      else if (aa[i-1] == bb[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
        mx = max(dp[i][j], mx);
      }
    return mx;
  }
};

void test(vi aa, vi bb) {
  Solution go;
  int r = go.findLength(aa, bb);
  output(r);
}

int main() {
  test({1, 2, 3, 2, 1}, {3, 2, 1, 4, 7});
  return 0;
}
