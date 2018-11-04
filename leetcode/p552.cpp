#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 50;
class Solution {
public:
  int findPaths(int m, int n, int kk, int x, int y) {
    int dp[N + 1][N][N] = {};
    fori (k, 1, kk + 1) {
      fori (i, 0, m) {
      fori (j, 0, n) {
        int up = (i == 0 ? 1 : dp[k-1][i-1][j]) % MOD;
        int down = (i == m-1 ? 1 : dp[k-1][i+1][j]) % MOD;
        int left = (j == 0 ? 1 : dp[k-1][i][j-1]) % MOD;
        int right = (j == n-1 ? 1 : dp[k-1][i][j+1]) % MOD;
        dp[k][i][j] = (up + down + left + right) % MOD;
      }
      }
    }
    return dp[kk][x][y];
  }
};

void test(int m, int n, int kk, int x, int y) {
  Solution go;
  int r = go.checkRecord(m, n, kk, x, y);
  output(r);
}

int main() {
  test(8, 50, 23, 5, 26);
  return 0;
}
