#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int rob(vector<int>& aa) {
    int n = sz(aa);
    if (n <= 0) return 0;
    if (n == 1) return aa[0];
    if (n == 2) return max(aa[0], aa[1]);

    int dp0[n], dp1[n];
    mst(dp0, 0);
    mst(dp1, 0);

    dp0[1] = aa[1], dp0[2] = max(aa[1], aa[2]);
    fori(i, 3, n) {
      dp0[i] = max(dp0[i-2] + aa[i], dp0[i-1]); 
    }

    dp1[0] = aa[0], dp1[1] = max(aa[0], aa[1]);
    fori(i, 2, n) {
      if (i == n-1)
        dp1[i] = dp1[i-1];
      else
        dp1[i] = max(dp1[i-2] + aa[i], dp1[i-1]);
    } 

    // fori(i, 0, n)
    //   cout << dp0[i] << " ";
    // cout << "\n";

    // fori(i, 0, n)
    //   cout << dp1[i] << " ";
    // cout << "\n";

    return max(dp0[n-1], dp1[n-1]);
  }
};

void TEST(vi aa) {
  Solution go;
  cout << go.rob(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 

  TEST({1,2,1,1});
  TEST({2,3,2});
  TEST({1,2,3,1});

  return 0;
}
