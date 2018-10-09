#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int search(vector<int>& aa, int target) {
    if (aa.size() == 0) return 0;
    int lo = 0, hi = aa.size() - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (aa[mid] == target) return true;
      if (aa[mid] > aa[hi]) {
        if (aa[lo] <= target && target < aa[mid]) hi = mid - 1;
        else lo = mid + 1;
      } else if (aa[mid] < aa[hi]) {
        if (aa[mid] < target && target <= aa[hi]) lo = mid + 1;
        else hi = mid - 1;
      } else {
        hi--;
      }
    }
    return aa[lo] == target ? true : false;
  }
};

int main(int argc, char** argv) {
  return 0;
}
