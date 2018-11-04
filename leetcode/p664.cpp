#include<bits/stdc++.h>
using namespace std;
// TODO
const int kk = 110;
// dp[i][j] denotes the minimum times needed to
// print string in the range of i...j.
int dp[kk][kk];

class Solution {
public:
  int strangePrinter(string s) {
  mst(dp, 0);
  int n = sz(s);
  if (n <= 1) return n;
  fori (i, 1, n + 1) {
    fori (lo, 0, n - i + 1) {
    int hi = lo + i - 1;
    dp[lo][hi] = i;
    fori(k, lo, hi) {
      int tmp = dp[lo][k] + dp[k+1][hi];
      if (s[lo] == s[k+1] || s[k] == s[hi]) --tmp;
      dp[lo][hi] = min(dp[lo][hi], tmp);
    }
    }
  }
  return dp[0][n-1];
  }
};

void test(string inp) {
  Solution go;
  int r = go.strangePrinter(inp);
  output(r);
}

int main() {
  test("aaabbb");
  test("aba");
  return 0;
}
