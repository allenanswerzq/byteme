#include<bits/stdc++.h>
using namespace std;

bool check(ll kk, vi& aa, int hh) {
  int res = 0;
  fora (a, aa) res += (a + kk - 1) / kk;
  return (res <= hh);
}

class Solution {
public:
  int minEatingSpeed(vector<int>& aa, int hh) {
    ll lo = 1, hi = *max_element(all(aa));
    while (lo < hi) {
      ll mid = lo + (hi - lo) / 2;
      if (check(mid, aa, hh)) hi = mid;
      else lo = mid + 1;
    }
    return lo;
  }
};

int main() {
  return 0;
}
