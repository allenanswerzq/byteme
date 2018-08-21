#include<bits/stdc++.h>
using namespace std;

        cout << "\n"; } cout << "\n"
        fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double eps = 1e-9;
int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class StripePainter
{
public:
  // dp[i][j] denotes the mininum number of paints needed 
  // if we paint in the range of i...j
  int dp[54][54];
  int minStrokes(string stripes) {
    mst2(dp, 54, 54, 0);
    int n = sz(stripes);
    fori(i, 0, n)
      dp[i][i] = 1;

    fori(size, 1, n) {
      fori(i, 0, n-size) {
        if (stripes[i] == stripes[i+size])
          dp[i][i+size] = dp[i][i+size-1];
        else {
          int t = 0x30303030;
          fori(k, 0, size) 
            t = min(t, dp[i][i+k] + dp[i+k+1][i+size]);
          dp[i][i+size] = t;
        }
      }
      prt2(dp, n, n);
    }
    return dp[0][n-1];
  }  
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  StripePainter go;
  cout << go.minStrokes("RGBGR") << "\n";
  // cout << go.minStrokes("RGRG") << "\n";
  // cout << go.minStrokes("ABACADA") << "\n";
  return 0;
}
