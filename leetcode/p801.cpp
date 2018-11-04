#include<bits/stdc++.h>
using namespace std;

const int size = 10002;
int dp0[size];
int dp1[size];
class Solution {
public:
  int minSwap(vector<int>& aa, vector<int>& bb) {
    int n = sz(aa);
    fori (i, 0, size) dp0[i] = 0;
    fori (i, 0, size) dp1[i] = 1;
    fori (i, 1, n) {
      dp0[i] = dp1[i] = n;
      if (aa[i-1] < aa[i] && bb[i-1] < bb[i]) {
      dp0[i] = dp0[i-1];
      dp1[i] = dp1[i-1] + 1;
      }

      if (aa[i-1] < bb[i] && bb[i-1] < aa[i]) {
      dp0[i] = min(dp0[i], dp1[i-1]);
      dp1[i] = min(dp1[i], dp0[i-1] + 1);
      }
    }
    // par(dp0, n);
    // par(dp1, n);
    return min(dp0[n-1], dp1[n-1]);
  }
};

void test(vi aa, vi bb) {
  Solution go;
  int r = go.minSwap(aa, bb);
  output(r);
}

int main() {
  test({1,3,5,4}, {1,2,3,7});
  return 0;
}
