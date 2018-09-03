#include<bits/stdc++.h>
using namespace std;


const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
const int kk = 110;
// dp[i][j] denotes the minimum times needed to 
// print string in the range of i...j.
int dp[kk][kk];

class Solution {
public:
  int strangePrinter(string s) {
  mst(dp, 0);
  int n = sz(s);
  if (n <= 1) return n;
  fori (i, 1, n + 1) {
  fori (lo, 0, n - i + 1) {
  int hi = lo + i - 1;
  dp[lo][hi] = i;
  fori(k, lo, hi) {
    int tmp = dp[lo][k] + dp[k+1][hi];
    if (s[lo] == s[k+1] || s[k] == s[hi]) --tmp;
    dp[lo][hi] = min(dp[lo][hi], tmp);
  }
  } 
  } 
  return dp[0][n-1];
  }
};

void test(string inp) {
  Solution go;
  int r = go.strangePrinter(inp);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  test("aaabbb");
  test("aba");
  return 0;
}
