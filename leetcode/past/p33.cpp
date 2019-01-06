#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // IDEA: one half of A must be sorted
  int search(vector<int>& aa, int target) {
    int n = aa.size();
    if (n == 0) return -1;
    int lo = 0, hi = n - 1;
    while ( lo < hi ) {

      int mid = lo + (hi - lo) / 2;
      if (aa[mid] == target)
      return mid;

      // Left part sorted
      if (aa[mid] > aa[hi]) {
        if (aa[lo] <= target && target < aa[mid]) hi = mid - 1;
        else lo = mid + 1;
      } else if (aa[mid] < aa[hi]) {
      // Right part sorted
        if(aa[mid] < target && target <= aa[hi]) lo = mid + 1;
        else hi = mid - 1;
      }
    }  
    return aa[lo] == target ? lo : -1;
  }
};

int main() {
  return 0;
}
