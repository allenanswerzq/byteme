#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& aa) {
    int res = aa[0];
    int i = 1, mx = res, mi = res;
    for (; i < n; ++i) {
      if (aa[i] < 0) swap(mx, mi);
      mx = max(mx, aa[i] * mx);
      mi = min(mi, aa[i] * mi);
      res = max(mx, res);
    }
    return mx;
  }
};

int main(int argc, char** argv) {
  return 0;
}
