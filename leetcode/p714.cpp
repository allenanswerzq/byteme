#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  int maxProfit(vector<int>& aa, int k) {
  int n = sz(aa);
  if (n <= 1) return 0;
  // Max profit we can get if we buy or sell at day `i`.
  int buy[n], sell[n];
  mst(buy, 0);
  mst(sell, 0);
  buy[0] = -aa[0];   
  fori(i, 1, n) {
    buy[i] = max(buy[i-1], sell[i-1] - aa[i]);  
    sell[i] = max(sell[i-1], buy[i-1] + aa[i] - k);
  }
  return max(buy[n-1], sell[n-1]);
  }
};

void test(vi aa, int k) {
  Solution go;
  int r = go.maxProfit(aa, k);
  cerr(r);    
}

int main() {
   test({1, 3, 2, 8, 4, 9}, 2);
  return 0;
}
