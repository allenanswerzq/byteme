#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
ll dp[51][50][50];
class Solution {
public:
  int findPaths(int m, int n, int kk, int x, int y) {
    mst(dp, 0);
    fori (k, 1, kk + 1) {
      fori (i, 0, m) {
      fori (j, 0, n) {
        ll up = (i == 0 ? 1 : dp[k-1][i-1][j]) % MOD;
        ll down = (i == m-1 ? 1 : dp[k-1][i+1][j]) % MOD;
        ll left = (j == 0 ? 1 : dp[k-1][i][j-1]) % MOD;
        ll right = (j == n-1 ? 1 : dp[k-1][i][j+1]) % MOD;
        dp[k][i][j] = (up + down + left + right) % MOD;
      }
      }
    }
    return dp[kk][x][y];
  }
};

int test(int m, int n, int kk, int x, int y) {
  Solution go;
  int r = go.findPaths(m, n, kk, x, y);
  output(r);
  return r;
}

int main() {
  judge(test(8, 50, 23, 5, 26), 914783380);
  return 0;
}
