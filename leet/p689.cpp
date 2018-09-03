#include<bits/stdc++.h>
using namespace std;


const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int dfs(vi& pre, int aa, int m, int k, int ix, vi res) {
  if (aa == 0) return 0;
  if (ix > m - 1) return 0;
  int mx = 0;
  int a = pre[ix] + dfs(pre, aa - 1, m, k, ix + k, res);
  int b = dfs(pre, aa, m, k, ix + 1, res);
  return max(a, b);
}

// TODO
const int ml = 20010;
int dp[3][ml];
// dp[i][j] = max(pre[ix] + dp[aa-1][j + k], dp[aa][ix+1])
vi dynamic(vi& pre, int m, int k) {
}

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& aa, int k) {
  int n, m;
  vi res;
  n = sz(aa);
  m = n - k + 1;
  vi pre(m, 0);

  fori (i, 0, k) pre[0] += aa[i];
  fori (i, 1, m) {
  pre[i] += pre[i - 1] + aa[i + k - 1] - aa[i - 1];
  } 

  // int mx = dfs(pre, 3, m, k, 0, res);
  dynamic(pre, 3, k);
  return res;
  }
};

void test(vi aa, int k) {
  Solution go;
  vi r = go.maxSumOfThreeSubarrays(aa, k);
  pvi(r);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  test({1,2,1,2,6,7,5,1}, 2);
  return 0;
}
