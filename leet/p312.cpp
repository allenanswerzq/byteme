#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int maxCoins(vector<int>& aa) {
    int n;
    if (sz(aa) <= 0) return 0;
    aa.insert(aa.begin(), 1);
    aa.insert(aa.end(), 1);
    n = sz(aa);

    // dp[i][j] denotes max coins we can get from array [i...j].
    // dp[i][j] = max(dp[i][k] + dp[k+1][j] + aa[i-1][k][j+1])
    int dp[n][n];
    mst(dp, 0);

    fori (j, 1, n-1) {
      ford (i, j, 0) {
        fori (k, i, j+1) {
          int tmp = dp[i][k-1]  + dp[k+1][j] + (aa[i-1]* aa[k] * aa[j+1]);
          dp[i][j] = max(dp[i][j], tmp);
        }
      } 
    }

    // fori(i, 0, n) {
    //   par(dp[i], n);
    // }

    return dp[1][n-2];
  }
};

void test(vi aa) {
  Solution go;
  cout << go.maxCoins(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({3, 1, 5, 8});
  return 0;
}
