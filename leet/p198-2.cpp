#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rob(vector<int>& aa) {
  int n = sz(aa);
  if (n <= 0) return 0;
  if (n == 1) return aa[0];
  int dp[n];
  mst(dp, 0);
  dp[0] = aa[0];
  dp[1] = max(aa[0], aa[1]);
  fori(i, 2, n) {
    dp[i] = max(dp[i-2] + aa[i], dp[i-1]);
  }
  return dp[n-1];
  }
};

void test(vi aa) {
  Solution go;
  cout << go.rob(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({1,2,3,1});
  test({2,7,9,3,1});
  return 0;
}
