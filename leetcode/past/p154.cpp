#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& aa) {
    int n = aa.size();
    int lo = 0, hi = n - 1;
    int res = INT_MAX;
    while (lo < hi) {
      while (hi >= 0 && aa[hi-1] == aa[hi]) --hi;
      while (lo < n - 1 && aa[lo+1] == aa[lo]) ++lo;
      int mid = lo + (hi - lo) / 2;
      if (aa[mid] <= aa[hi]) {
        res = min(res, aa[mid]);
        hi = mid-1;
      } else {
        res = min(res, aa[lo]);
        lo = mid+1;
      }
    }    
    res = min(res, aa[lo]);
    return res;
  }
};

int main() {
  return 0;
}
