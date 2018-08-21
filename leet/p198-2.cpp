#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int rob(vector<int>& aa) {
    int n = sz(aa);
    if (n <= 0) return 0;
    if (n == 1) return aa[0];
    if (n == 2) return max(aa[0], aa[1]);
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

void TEST(vi aa) {
  Solution go;
  cout << go.rob(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  TEST({1,2,3,1});
  TEST({2,7,9,3,1});
  return 0;
}
