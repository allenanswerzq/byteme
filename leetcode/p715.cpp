#include <bits/stdc++.h>
using namespace std;

// TODO
class RangeModule {
public:
  RangeModule() {
    lo = inf;
    hi = -inf;
  }

  void addRange(int left, int right) {
    lo = min(left, lo);
    hi = max(right, hi);
  }

  bool queryRange(int left, int right) {
    if (left >= lo && right < hi) return 1;
    else return 0;
  }

  void removeRange(int left, int right) {
    lo = max(lo, left);
    hi = min(hi, right);
  }
  int lo;
  int hi;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

int main() {
  return 0;
}
