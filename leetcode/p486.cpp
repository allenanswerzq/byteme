#include<bits/stdc++.h>
using namespace std;
int recu(vi& aa, int lo, int hi, int turn) {
  if (lo == hi) return turn * aa[lo];
  int a = turn * aa[lo] + recu(aa, lo + 1, hi, -turn);
  int b = turn * aa[hi] + recu(aa, lo, hi - 1, -turn);
  return turn * max(turn * a, turn * b);
}

const int N = 1000;
int dp[N][N];
int recu2(vi& aa, int lo, int hi) {
  if (lo == hi) return aa[lo];
  if (dp[lo][hi] != -1) return dp[lo][hi];
  int a = aa[lo] - recu2(aa, lo + 1, hi);
  int b = aa[hi] - recu2(aa, lo, hi - 1);
  dp[lo][hi] = max(a, b);
  return dp[lo][hi];
}

// TODO
class Solution {
public:
  bool PredictTheWinner(vector<int>& aa) {
    // return recu(aa, 0, sz(aa)-1, 1) >= 0;
    mst(dp, -1);
    return recu2(aa, 0, sz(aa)-1) >= 0;
  }
};

void test(vi aa) {
  Solution go;
  int r = go.PredictTheWinner(aa);
  output(r);
}

int main() {
  test({1, 5, 2});
  test({1, 5, 233, 7});
  return 0;
}
