#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int nthUglyNumber(int n) {
  int dp[n+1];
  mst(dp, 0);
  dp[1] = 1;

  int a, b, c;
  a = b = c = 1; 
  fori(i, 2, n+1) {
    int cur = dp[i-1];
    while (dp[a] * 2 <= cur) ++a;
    while (dp[b] * 3 <= cur) ++b;
    while (dp[c] * 5 <= cur) ++c;
    dp[i] = min(dp[a] * 2, min(dp[b] * 3, dp[c] * 5));
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
