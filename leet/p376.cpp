#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int wiggleMaxLength(vector<int>& aa) {
    int n, res;
    n = sz(aa);
    if (n <= 1) return n;
    int dp[n][2];
    fori(i, 0, n)
      dp[i][0] = dp[i][1] = 1;
    res = 0;
    fori (i, 1, n) {
      fori (j, 0, i) {
        if (aa[j] < aa[i])
          dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        if (aa[j] > aa[i])
          dp[i][1] = max(dp[i][1], dp[j][0] + 1);
      }
      res = max(res, dp[i][0]);
      res = max(res, dp[i][1]);
    }     
    return res;
  }
};

void test(vi aa) {
  Solution go;
  cout << go.wiggleMaxLength(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({1, 7, 4, 9, 2, 5});
  test({0, 0});
  return 0;
}
