#include<bits/stdc++.h>
using namespace std;


const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
class Solution {
public:
  int minSteps(int n) {
  int dp[n + 1];
  mst(dp, 0);
  fori (i, 2, n+1) {
  dp[i] = i;
  ford (j, i-1, 1) {
  if (i % j == 0) 
    // dp[j] + copy all + past i / j - 1 times
    dp[i] = dp[j] + i / j;
    break;
  }
  } 
  return dp[n];
  }
};

void test() {
  Solution go;
  int r;
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
