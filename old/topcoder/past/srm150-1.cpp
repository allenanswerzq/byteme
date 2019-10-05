#include<bits/stdc++.h>
using namespace std;

class StripePainter {
public:
  // dp[i][j] denotes the mininum number of paints needed
  // if we paint in the range of i...j
  int dp[54][54];
  int minStrokes(string stripes) {
    mst(dp, 0);
    int n = sz(stripes);
    fori (i, 0, n)
      dp[i][i] = 1;

    fori (size, 1, n) {
      fori (i, 0, n - size) {
        if (stripes[i] == stripes[i + size])
          dp[i][i + size] = dp[i][i + size - 1];
        else {
          int t = 0x30303030;
          fori (k, 0, size)
            t = min(t, dp[i][i + k] + dp[i + k + 1][i + size]);
          dp[i][i + size] = t;
        }
      }
    }
    return dp[0][n-1];
  }
};

void test(string aa) {
  StripePainter go;
  int r = go.minStrokes(aa);
  output(r);
}

int main() {
  test("RGBGR");
  test("RGRG");
  test("ABACADA");
  return 0;
}
