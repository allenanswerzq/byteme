#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
class Solution {
public:
  
  int maxProfit(vector<int>& prices) {
    int n = sz(prices);
    int res = 0;
    int sum = 0;
    fori(i, 0, n-1) {
      int diff = prices[i+1] - prices[i];
      if (sum >= 0) 
        sum += diff;
      else 
        sum = diff;
      res = max(res, sum);
    }
    return res;
  }

  int maxProfit(vi& prices) {
    int n = sz(prices);
    int mi = (1<<31) - 1;
    int res = 0;
    fori (i, 0, n) {
      mi = min(mi, prices[i]);
      res = max(res, prices[i] - mi);
    } 
    return res;
  }

  // int maxProfit(vector<int>& prices) {
  //   int n = sz(prices);
  //   if (n <= 0) return 0;

  //   // The max profit i can get when sell stock at `ith` day.
  //   int dp[n]; 
  //   mst(dp, 0);
  //   int mi = prices[0];

  //   fori(i, 1, n) {
  //     int diff = prices[i] - prices[i-1];
  //     if (prices[i] < mi)
  //       mi = prices[i];

  //     if (diff > 0)
  //       dp[i] = dp[i-1] + prices[i] - prices[i-1]; 
  //     else {
  //       dp[i] = prices[i] - mi;
  //     }
  //   }

  //   int res = 0;
  //   fori(i, 0, n)
  //     res = max(res, dp[i]);

  //   // fori(i, 0, n)
  //   //   cout << dp[i] << " ";
  //   // cout << "\n";

  //   return res;
  // }
};

void TEST(vi inp) {
  Solution go;
  cout << go.maxProfit(inp) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 

  TEST({7, 1, 5, 3, 6, 4});
  TEST({7, 6, 5, 4, 3});
  TEST({2, 4, 1});

  return 0;
}
