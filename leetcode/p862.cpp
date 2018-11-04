#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int shortestSubarray(vector<int>& aa, int kk) {
    int n = sz(aa);
    if (n == 0) return -1;
    int res = (1 << 20);
    ll pre_sum = 0;
    vector<pair<ll, int>> sums;
    sums.eb(0, -1);
    fori (i, 0, n) {
      pre_sum += aa[i];
      int pos = upper_bound(all(sums), mk(pre_sum - kk, 1<<20)) - sums.begin();
      --pos;
      if (pos >= 0) res = min(res, i - sums[pos].se);
      // trace(pre_sum, pos, res);
      while (sz(sums) && sums.back().fi >= pre_sum) sums.ppb();
      sums.pb({pre_sum, i});
    }
    return res == (1<<20) ? -1 : res;
  }
};

int main() {
  return 0;
}
