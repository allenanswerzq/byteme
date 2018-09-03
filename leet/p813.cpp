#include<bits/stdc++.h>
using namespace std;




const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
const int size = 105;
double dp[size][size];
class Solution {
public:
  double largestSumOfAverages(vector<int>& aa, int kk) {
  int n = sz(aa);
  aa.insert(aa.begin(), 0);
  dp[0][0] = 0;
  fori (k, 1, kk + 1) {
    fori (i, 1, n + 1) {
    double sum = 0;
    ford (j, i-1, -1) {
      sum += aa[j + 1];
      if (dp[j][k-1] == -1) continue;
      dp[i][k] = max(dp[i][k], dp[j][k-1] + sum / (i - j));
    }
    }
  }

  // fori (i, 0, n + 1) {
  //   par(dp[i], kk + 1);
  // }

  return dp[n][kk];
  }
};

void test(vi aa, int k) {
  Solution go;
  int r = go.largestSumOfAverages(aa, k);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(4);
  cout << fixed; 
  test({9, 1, 2, 3, 9}, 3);
  return 0;
}
