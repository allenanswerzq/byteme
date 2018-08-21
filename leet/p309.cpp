#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int maxProfit(vector<int>& aa) {
    int n = sz(aa);
    if (n <= 1) return 0;
    // The max profit we can get till index i ending with a buy.
    int buy[n + 1];
    // The max profit we can get till index i ending with a sell. 
    int sell[n + 1]; 
    mst(buy, 0);
    mst(sell, 0);
    sell[1] = 0;
    buy[1] = -aa[0];
    fori(i, 2, n+1) {
      // Sells at `i - 2` cooldown at `i-1` and buy at `i`. Since we will buy 
      // at `i`, so the max profit will be decreased by aa[i].
      buy[i] = max(buy[i - 1], sell[i - 2] - aa[i-1]);
      // Since we want to sell at day `i`, we can buy at day `i-1`.
      sell[i] = max(sell[i - 1], buy[i - 1] + aa[i-1]);
    }
    return max(buy[n], sell[n]);
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

  TEST({1,2,3,0,2});
  TEST({1, 2, 4});
  
  return 0;
}
