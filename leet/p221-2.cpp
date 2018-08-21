#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int maximalSquare(vector<vector<char>>& aa) {
    if (sz(aa) <= 0) return 0;
    int n, m;
    n = sz(aa);
    m = sz(aa[0]); 

    int dp[n][m];
    mst(dp, 0);

    int res = 0;
    fori(i, 0, n) {
      fori(j, 0, m) {
        if (i == 0)
          dp[i][j] = aa[i][j] - '0';
        else if (j == 0)
          dp[i][j] = aa[i][j] - '0';
        else if (aa[i][j] == '1') {
          dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
        }
      }
    }

    // fori(i, 0, n) {
    //   fori(j, 0, m)
    //     cout << dp[i][j] << " ";
    //   cout << "\n";
    // }

    fori(i, 0, n) 
      fori(j, 0, m)
        res = max(res, dp[i][j] * dp[i][j]);
    return res;
  }
};

void TEST(vvi aa) {
  Solution go;
  cout << go.maximalSquare(aa) << "\n"; 
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  vvi aa = {{1,0,1,0,0},
            {1,0,1,1,1}, 
            {1,1,1,1,1},
            {1,0,0,1,0}};
  TEST(aa); 
  return 0;
}
