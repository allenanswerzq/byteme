#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
class Solution {
public:
  int numTrees(int n) {
  int dp[n + 1];
  mst(dp, 0);
  dp[0] = 1;
  dp[1] = 1;
  fori (i, 2, n + 1) {
  fori (j, 0, i) {
  dp[i] += dp[j] * dp[i - j - 1];
  }
  }
  return dp[n];
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
