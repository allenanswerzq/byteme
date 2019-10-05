#include<bits/stdc++.h>
using namespace std;

// TDOD
class BadNeighbors {
public:
  int maxDonations(vi aa) {
    int n = sz(aa);
    vi dp1(n + 1, 0), dp2(n + 1, 0);
    dp1[0] = aa[0];
    dp2[1] = aa[1];

    int res = 0;
    // Note: not reach to the last one person,
    // Because we include the first person here.
    fori (i, 0, n-1) {
      int r = 0;
      fori (j, 0, i-1)
        if (r < dp1[j]) r = dp1[j];
      dp1[i] = aa[i] + r;
      // pvi(dp1, 1);
      res = max(res, dp1[i]);
    }
    // Note: not include the first person,
    // Because we use the last person's money.
    fori (i, 1, n) {
      int r = 0;
      fori (j, 1, i-1)
        if (r < dp2[j]) r = dp2[j];
      dp2[i] = aa[i] + r;
      // pvi(dp2, 1);
      res = max(res, dp2[i]);
    }
    return res;

  }
};

void test(vi aa) {
  BadNeighbors go;
  auto r = go.maxDonations(aa);
  output(r);
}

int main() {
  test({10, 3, 2, 5, 7, 8 });
  test({11, 3 });
  test({7, 7, 7, 7, 7, 7, 7 });
  test({1, 2, 3, 4, 5, 1, 2, 3, 4, 5 });
  test({94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 });
  return 0;
}
