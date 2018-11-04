#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(int k, vector<int> &aa) {
    if (aa.empty()) return 0;
    if (k >= aa.size()) return solveMaxProfit(aa);
    int global[k + 1] = {0};
    int local[k + 1] = {0};
    for (int i = 0; i < aa.size() - 1; ++i) {
      int diff = aa[i + 1] - aa[i];
      for (int j = k; j >= 1; --j) {
        local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
        global[j] = max(global[j], local[j]);
      }
    }
    return global[k];
  }
  
  int solveMaxProfit(vector<int> &aa) {
    int res = 0;
    for (int i = 1; i < aa.size(); ++i) {
      if (aa[i] - aa[i - 1] > 0) {
        res += aa[i] - aa[i - 1];
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
