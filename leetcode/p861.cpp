#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int matrixScore(vector<vector<int>>& aa) {
    int n = sz(aa);
    int m = sz(aa[0]);
    fori (i, 0, n) {
      if (aa[i][0] == 0) {
      fori (j, 0, m)
        aa[i][j] ^= 1;
      }
    }

    int res = 0;
    fori (j, 0, m) {
      int one = 0;
      fori (i, 0, n)
      if (aa[i][j] == 1) ++one;
      res += max(one, n - one) * (1 << (m - j - 1));
    }
    return res;
  }
};

int main() {
  return 0;
}
