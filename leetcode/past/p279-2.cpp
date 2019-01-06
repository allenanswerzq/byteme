#include <bits/stdc++.h>
using namespace std;

int recu(int n) {
  if (n <= 3) return n;
  int res = n;
  int to = (int)sqrt(n) + 1;
  fori(i, 1, to) {
  int tmp = i * i;
  res = min(res, 1 + recu(n - tmp));  
  }
  return res;
}

class Solution {
public:
  int numSquareDP(int n) {
  int dp[n+1];
  mst(dp, 0);
  dp[1] = 1;
  fori(i, 2, n+1) {
    int res = i;
    fori(j, 1, i) {
    if (j * j > i) break;
      res = min(res, dp[i - j * j] + 1);
    }
    dp[i] = res;
  }
  return dp[n];
  }

  int numSquares(int n) {
  // return recu(n); 
  return numSquareDP(n);
  }
};

void TEST(int n) {
  Solution go;
  cout << go.numSquares(n) << "\n";
}

int main() {
 
  TEST(12);
  TEST(13);

  return 0;
}
