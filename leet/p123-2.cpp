#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int helper(vi& aa, int lo, int hi) {
  if (lo >= hi) return 0;
  int mi = aa[lo];
  int res = 0;
  fori(i, lo, hi+1) {
  if (aa[i] < mi) 
    mi = aa[i];
  res = max(res, aa[i] - mi);
  }
  return res;
}

// TODO
class Solution {
public:

  int maxProfitOne(vector<int>& aa) {
  int n = sz(aa);
  int res = 0;
  fori(i, 0, n) {
    // Complete one transaction in the range [0...i]
    int x = helper(aa, 0, i);
    // Complete another transaction in the range [i+1...n-1]
    int y = helper(aa, i+1, n-1);
    res = max(res, x + y);
  } 
  return res;
  }

  int maxProfitTwo(vi aa) {
  int n = sz(aa);
  if (n <= 0) return 0;
  // dp[i] denotes the max profit in the range of [i...n].
  int dp[n];
  mst(dp, 0);

  int mx = aa[n-1];
  // buy at ith day, sell at the `mx` day.
  ford(i, n-2, -1) {
    if (aa[i] > mx)
    mx = aa[i];
    dp[i] = max(dp[i+1], mx - aa[i]);
  } 

  int mi = aa[0];
  fori(i, 1, n) {
    if (aa[i] < mi)
    mi = aa[i];
    dp[i] = max(dp[i-1], dp[i] + aa[i] - mi);
  } 

  return dp[n-1];
  }

  // https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/
  int maxProfitThree(vi aa) {
  int n = sz(aa);
  if (n <= 0) return 0;

  // Let dp[t][i] represent maximum profit using at most t transactions 
  // up to day i (including day i). Then the relation is:
  // dp[t][i] = max(dp[t][i-1], max(price[i] – price[j] + dp[t-1][j]))
  //      for all j in range [0, i-1]

  int dp[3][n + 1];
  fori(i, 0, 3) {
    fori(j, 0, n+1) {
    if (i == 0)
      dp[i][j] = 0;
    else if (j == 0)
      dp[i][j] = 0;
    else {
      int mx = 0;
      fori(k, 0, j) {
      mx = max(mx, dp[i-1][k] + aa[j] - aa[k]);
      }
      dp[i][j] = max(dp[i][j-1], mx);
    }
    }
  }
  return dp[2][n-1];
  }

  int maxProfit(vi aa) {
  srand(time(0));
  int x = rand();
  // x = 1;
  if (x % 3 == 0) 
    return maxProfitOne(aa);
  else if (x % 3 == 1)
    return maxProfitTwo(aa);
  else 
    return maxProfitThree(aa);
  }

};

void TEST(vi aa) {
  Solution go;
  cout << go.maxProfit(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 

  TEST({3,3,5,0,0,3,1,4});
  TEST({1,2,3,4,5});
  TEST({7,6,4,3,1});

  return 0;
}
