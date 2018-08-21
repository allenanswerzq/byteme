#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int lengthOfLIS(vector<int>& aa) {
    int n = sz(aa);
    if (n <= 1) return n;
    int dp[n];
    mst(dp, 0);
    dp[0] = 1;    
    fori(i, 1, n) {
      int mi = 1;
      fori(j, 0, i) {
        if (aa[i] > aa[j])
          mi = max(mi, dp[j] + 1); 
      }
      dp[i] = mi;
    }

    // fori(i, 0, n)
    //   cout << dp[i] << " ";
    // cout << "\n";

    int res = 0;
    fori(i, 0, n)
      res = max(res, dp[i]);
    return res;
  }
};

void TEST(vi aa) {
  Solution go;
  cout << go.lengthOfLIS(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  TEST({10, 9, 2, 5, 3, 5, 101, 18});
  TEST({1,3,6,7,9,4,10,5,6});
  return 0;
}
