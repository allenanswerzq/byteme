#include <bits/stdc++.h>
using namespace std;

int res;

void dfs(vi& aa, int ix, int sum, int goal) {
  int n = sz(aa);
  if (ix == n) {
    if (sum == goal) ++res;
    return;
  }
  int tmp = sum;
  sum += aa[ix];
  dfs(aa, ix + 1, sum, goal);
  sum = tmp;
  sum -= aa[ix];
  dfs(aa, ix + 1, sum, goal);
}

int findTargetSumWaysDFS(vector<int>& aa, int goal) {
  res = 0;
  dfs(aa, 0, 0, goal);
  return res;
}

int go(vi& aa, int goal) {
  int n = sz(aa);
  // dp[i] denotes the number of ways that
  // the sum of the subset of aa equals `i`.
  int dp[goal + 1];
  mst(dp, 0);
  dp[0] = 1;
  fora (a, aa) {
    ford (i, goal, a - 1) {
      dp[i] += dp[i - a];
    }
  }
  return dp[goal];
}

int findTargetSumWaysDP(vi& aa, int goal) {
  int n = sz(aa);
  int sum = accumulate(all(aa), 0);

  if (sum < goal || (goal + sum) % 2 != 0) return 0;
  else return go(aa, (goal + sum) / 2);
}

class Solution {
public:
  int findTargetSumWays(vi& aa, int goal) {
    return findTargetSumWaysDP(aa, goal);
    // return findTargetSumWaysDFS(aa, goal);
  }
};

void test(vi& aa, int goal) {
  Solution go;
  int r = go.findTargetSumWays(aa, goal);
  output(r);
}

int main() {
  test({1, 1, 1, 1, 1,}, 3);
  test({1, 1, 1, 1}, 2);
  return 0;
}
