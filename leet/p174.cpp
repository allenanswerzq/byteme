#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& aa) {
  int n, m;
  m = sz(aa), n = sz(aa[0]); 
  // dp[i][j] denotes the minimum points before enter `(i,j)`,
  // that can guarantee himself reaches to the final goal.
  int dp[m][n];
  mst(dp, 0);

  ford (i, m-1, -1) {
  ford (j, n-1, -1) {
  if (i == m-1 && j == n-1) 
    dp[i][j] = max(1, 1 - aa[i][j]);

  else if (i == m-1) {
    // Last row.
    dp[i][j] = max(dp[i][j+1] - aa[i][j], 1);
  } 
  else if (j == n-1) {
    // Last column.
    dp[i][j] = max(dp[i+1][j] - aa[i][j], 1);
  } 
  else {
    int mi = min(dp[i+1][j], dp[i][j+1]);
    dp[i][j] = max(mi - aa[i][j], 1);
  }
  }
  }

  // fori(i, 0, m) {
  //   fori(j, 0, n)
  //     cout << dp[i][j] << " ";
  //   cout << "\n";
  // }

  return dp[0][0];
  }
};

void TEST(vvi aa) {
  Solution go;
  cout << go.calculateMinimumHP(aa) << "\n"; 
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  vvi aa = {
  {-2, -3, 3},
  {-5, -10, 1},
  {10, 30, -5}};
  TEST(aa);
  TEST({{1,0,0}});
  return 0;
}
