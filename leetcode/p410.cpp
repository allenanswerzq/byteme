#include <bits/stdc++.h>
using namespace std;

vi bb;
vi sum;

bool check(int inp, int m) {
  int cnt, tot;
  tot = 0;
  cnt = 1;
  fora (b, bb) {
  tot += b;
  if (tot > inp) {
    tot = b;
    ++cnt;
    if (cnt > m)
    return 0;
  }
  }
  // cerr(cnt);
  return 1;
}

int splitArrayBinSearch(int m) {
  int lo, hi, mid;
  lo = *max_element(all(bb));
  hi = accumulate(all(bb), 0);
  // cerr(lo);
  // cerr(hi);
  while (lo < hi) {
    mid = lo + (hi - lo) / 2;
    if (check(mid, m)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

const int M = 100;
const int N = 2000;
// dp[i][j] denotes minimum largest sum value we can get if we split array in
// the range of [0...j-1] with `i` partitions.
int dp[M][N];
int splitArrayDP(int m, int n) {
  fori (i, 0, M) fori (j, 0, N)
    dp[i][j] = INT_MAX;

  dp[0][0] = 0;
  fori (i, 1, m+1) fori (j, 0, n+1) fori (k, 0, j) {
    int tmp = max(dp[i-1][k], sum[j] - sum[k]);
    dp[i][j] = min(dp[i][j], tmp);
  }
  return dp[m][n];
}

class Solution {
public:
  int splitArray(vector<int>& aa, int m) {
    bb = aa;
    int n = sz(aa);
    sum.resize(n + 1);
    fori (i, 1, n+1)
      sum[i] = sum[i-1] + aa[i-1];
    // return splitArrayDP(m, n);
    return splitArrayBinSearch(m);
  }
};

void test(vi aa, int n) {
  Solution go;
  int x = go.splitArray(aa, n);
  output(x);
}

int main() {
  test({7, 2, 5, 10, 8}, 2);
  test({5, 1, 3, 5, 10, 7, 4, 9, 2, 8}, 1);
  test({1, 2147483646}, 1);
  test({1, 4, 4}, 3);
  return 0;
}
