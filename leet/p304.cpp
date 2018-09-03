#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> matrix) {
  fora (e, matrix)
  dp.pb(go(e));
  }
  
  vi go(vi aa) {
  int n = sz(aa);
  vi dp(n+1, 0);
  fori(i, 1, n+1)
  dp[i] = dp[i-1] + aa[i-1];
  return dp;
  } 

  int sumRegion(int row1, int col1, int row2, int col2) {
  int sum = 0;
  fori (i, row1, row2+1) 
  sum += dp[i][col2 + 1] - dp[i][col1];
  return sum;
  }

private:
  vvi dp;
};


class NumMatrix {
public:
  NumMatrix(vvi& matrix) {
  int m = sz(matrix), n = sz(matrix[0]);
  if (m == 0) return; 
  dp.resize(m + 1, vi(n + 1, 0));
  fori (i, 1, m + 1) {
  fori (j, 1, n + 1) {
  dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + matri[i-1][j-1];
  }
  }
  }

  int sumRegion(int r1, int c1, int r2, int c2) {
  return dp[r2 + 1][c2 + 1] - dp[r1][c2 + 1] - dp[r2 + 1][c1] + dp[r1][c1];
  }

private:
  // dp[i][j] denotes the sum of matirx (0, 0, i - 1, j - 1).
  vvi dp;
};

void test(vvi aa) {
  NumMatrix go(aa);
  cout << go.sumRegion(2, 1, 4, 3) << "\n";
  cout << go.sumRegion(1, 1, 2, 2) << "\n";
  cout << go.sumRegion(1, 2, 2, 4) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 

  vvi aa = {{3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5}};
  test(aa);

  return 0;
}
