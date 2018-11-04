#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
int dp[N][N];
int recu(int lo, int hi) {
  if (lo >= hi) return 0;
  if (dp[lo][hi]) return dp[lo][hi];
  int res = inf;
  // xi = xi + max(dp[1][xi-1], dp[xi+1][hi]);
  // dp[i][j] = min({xi, xi+1, xi+2, ... xj})
  fori (i, lo, hi+1) {
  int tmp = i + max(recu(lo, i-1), recu(i+1, hi));
  res = min(res, tmp);
  } 
  // cout << lo << " " << hi << " " << res << "\n";
  dp[lo][hi] = res;
  return res;
}

class Solution {
public:
  int getMoneyAmountDP(int n) {
  mst(dp, 0);
  fori (j, 2, n+1) {
    ford (i, j-1, 0) {
    int res = inf;
    fori (k, i, j+1) {
      int tmp = k + max(dp[i][k-1], dp[k+1][j]);
      res = min(res, tmp);
    }
    dp[i][j] = res;
    }
  }      
  return dp[1][n];
  }

  int getMoneyAmountRecu(int n) {
  mst(dp, 0);
  return recu(1, n);
  }

  int getMoneyAmount(int n) {
  // return getMoneyAmountRecu(n);
  return getMoneyAmountDP(n);
  }
};

void test(int n) {
  Solution go;
  cout << go.getMoneyAmount(n) << "\n";
}

int main() {
   test(10);
  return 0;
}
