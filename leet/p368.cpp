#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& aa) {
  int n, best;
  n = sz(aa);
  if (n <= 1) return aa;
  // dp[i] denotes the maximum size of divisible subset 
  // ending with `ith` element.
  int dp[n], pre[n];
  sort(all(aa)); 
  mst(dp, 1);
  mst(pre, -1);
  best = 0;
  fori (i, 1, n) {
    fori (j, 0, i) {
    if (aa[i] % aa[j] == 0) {
      if (dp[i] < dp[j] + 1) {
      dp[i] = dp[j] + 1;
      pre[i] = j;
      }
    } 
    }
    if (dp[best] < dp[i]) 
    best = i;
  }

  // par(aa, n);
  // par(dp, n);

  vi res;
  while (best != -1) {
    res.insert(res.begin(), aa[best]);
    best = pre[best];
  }
  return res;
  }
};

void test(vi aa) {
  Solution go;
  vi res = go.largestDivisibleSubset(aa);
  pvi(res);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({1, 2, 3});
  test({1, 2, 4, 8});
  test({1, 2, 4, 3, 9, 27});
  test({2,3,8,9,27});
  return 0;
}
