#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& aa) {
  int n = sz(aa);
  if (n <= 1) return n;
  int dp[n];
  mst(dp, 0);
  dp[0] = 1;    
  fori (i, 1, n) {
    fori (j, 0, i) {
    if (aa[i] > aa[j])
      dp[i] = max(dp[i], dp[j] + 1); 
    }
  }

  int res = 0;
  fori (i, 0, n)
    res = max(res, dp[i]);
  return res;
  }
};

void test(vi aa) {
  Solution go;
  cout << go.lengthOfLIS(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({10, 9, 2, 5, 3, 5, 101, 18});
  test({1,3,6,7,9,4,10,5,6});
  return 0;
}
