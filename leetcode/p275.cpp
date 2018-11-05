#include <bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  int hIndex(vector<int>& aa) {
    int len = aa.size(), lo = 0, hi = len - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo);
      if (aa[mid] == len - mid) return len - mid;
      else if (aa[mid] > len - mid) hi = mid - 1;
      else lo = mid + 1;
    }
    return len - lo;
  }
};


