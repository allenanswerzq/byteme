#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
class Solution {
public:
  int maxSubArray(vector<int>& aa) {
    int n = sz(aa);
    // dp[i] denotes the maximum subarray ending at `ith` position.
    int dp[n];
    mst(dp, 0);
    dp[0] = aa[0];
    int res = aa[0];
    fori (i, 1, n) {
      dp[i] = max(aa[i], dp[i-1] + aa[i]); 
      res = max(res, dp[i]);
    } 
    return res;
  }
};

class Solution {
public:
  int maxSubArray(vector<int>& aa) {
    int n = sz(aa);
    int tmp = aa[0];
    int res = aa[0];
    fori (i, 1, n) {
      tmp = max(aa[i], tmp + aa[i]); 
      res = max(res, tmp);
    } 
    return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
