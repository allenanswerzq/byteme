#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int aa = 1002;
// dp[i][j] denotes the number of arrays that formed by 1....i and have 
// j inverse pairs.
ll dp[aa][aa];

class Solution {
public:
  int kInversePairs(int n, int k) {
    // The biggest for k should be n*(n-1)/2 when n numbers are reverse placed.
    if (k > n*(n-1)/2 || k<0) return 0; 
    // Ascending order or descending order.
    if (k==0 && k == n*(n-1)/2) return 1;
    mst(dp, 0);
    dp[2][0] = 1;
    dp[2][1] = 1;
    fori (i, 3, n+1) {
      dp[i][0] = 1;
      int hi = min(k, n * (n-1) / 2) + 1;
      fori (j, 1, hi) {
        dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
        if (j >= i) dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod;
      }
    } 
    return dp[n][k];
  }
};

void test(int n, int k) {
  Solution go;
  int r = go.kInversePairs(n, k);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  test(3, 1);
  test(3, 0);
  test(1000, 1000);
  return 0;
}
