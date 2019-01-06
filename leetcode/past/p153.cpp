#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& aa) {
    int n = aa.size();
    int lo = 0, hi = n - 1;
    int res = INT_MAX;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (aa[lo] <= aa[mid]) {
        res = min(aa[lo], res);
        lo = mid + 1;
      } else {
        res = min(aa[mid], res);
        hi = mid - 1; 
      }
    }    
    return res;
  }
};

int main() {
  return 0;
}
