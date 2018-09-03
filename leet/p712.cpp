#include<bits/stdc++.h>
using namespace std;




const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
  int m, n;
  m = sz(s1), n = sz(s2);
  int dp[m + 1][n + 1];
  mst(dp, 0);
  fori (i, 0, m + 1) 
  fori (j, 0, n + 1) {
  if (i == 0 && j==0)
    dp[i][j] = 0;
  else if (i == 0)
    dp[0][j] = dp[0][j-1] + s2[j-1];
  else if (j == 0)
    dp[i][0] = dp[i-1][0] + s1[i-1];
  else if (s1[i - 1] == s2[j - 1])
    dp[i][j] = dp[i-1][j-1];
  else 
    dp[i][j] = min(dp[i-1][j] + s1[i - 1], 
       dp[i][j-1] + s2[j - 1]);
  }        
  return dp[m][n];
  }
};

void test(string s1, string s2) {
  Solution go;
  int r = go.minimumDeleteSum(s1, s2);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  test("sea", "eat");
  test("delete", "leet");
  return 0;
}
