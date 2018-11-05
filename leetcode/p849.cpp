#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDistToClosest(vector<int>& aa) {
    int n = sz(aa);
    int inf = 0x3f3f3f3f;
    vi dp1(n, -1);
    vi dp2(n, -1);

    // Left to right.
    int pre = -inf;
    fori(i, 0, n) {
      if (aa[i] == 1) pre = i;
      else dp1[i] = i - pre;
    }

    // Right to left.
    pre = inf;
    ford(i, n-1, -1) {
      if (aa[i] == 1) pre = i;
      else dp2[i] = pre - i;
    }

    int res = 0;
    fori(i, 0, n) {
      if (dp1[i] != -1 && dp2[i] != -1)
      res = max(res, min(dp1[i], dp2[i]));
    }
    return res;
  }
};

int main() {
  return 0;
}
