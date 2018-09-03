#include<bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  int maxSubArray(vector<int>& aa) {
    int n = sz(aa);
    // dp[i] denotes the maximum subarray ending at `ith` position.
    int dp[n]; mst(dp, 0);
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
    int tmp = 0;
    int res = 0;
    fori (i, 0, n) {
      tmp = max(aa[i], tmp + aa[i]); 
      res = max(res, tmp);
    } 
    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}
