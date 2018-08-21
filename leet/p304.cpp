#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> matrix) {
    fora(e, matrix)
      dp.pb(helper(e));
  }
  
  vi helper(vi aa) {
    int n = sz(aa);
    vi dp(n+1, 0);
    fori(i, 1, n+1)
      dp[i] = dp[i-1] + aa[i-1];
    return dp;
  } 

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    fori(i, row1, row2+1) 
        sum += dp[i][col2 + 1] - dp[i][col1];
    return sum;
  }

private:
  vvi dp;
};

void TEST(vvi aa) {
  NumMatrix go(aa);
  cout << go.sumRegion(2, 1, 4, 3) << "\n";
  cout << go.sumRegion(1, 1, 2, 2) << "\n";
  cout << go.sumRegion(1, 2, 2, 4) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  vvi aa = {
  {3, 0, 1, 4, 2},
  {5, 6, 3, 2, 1},
  {1, 2, 0, 1, 5},
  {4, 1, 0, 1, 7},
  {1, 0, 3, 0, 5}};
  TEST(aa);
  return 0;
}
