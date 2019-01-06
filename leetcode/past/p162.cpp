#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& aa) {
    int lo = 0; hi = aa.size() - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (aa[mid] > aa[mid + 1])
        hi = mid;
      else
        lo = mid + 1;
    }
    return lo;
  }

  int findPeakElement(vector<int>& aa) {
    for (int i = 1; i < aa.size(); ++i) {
      // because aa[-1] = aa[n] = -inf
      // the first descending positon is a peak
      // or it will be a ascending order, namely the last one is a peak
      if (aa[i-1] > aa[i])
        return i - 1;
    }
    return aa.size() - 1;
  }
};

int main() {
  return 0;
}
