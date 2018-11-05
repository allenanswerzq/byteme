#include <bits/stdc++.h>
using namespace std;

int recu(string ss, string tt, int ls, int lt) {
  if (ls == 0) return 0;
  if (lt == 0) return 1;
  if (ss[ls - 1] != tt[lt - 1]) {
    return recu(ss, tt, ls - 1, lt);
  } else {
    return recu(ss, tt, ls - 1, lt) + recu(ss, tt, ls - 1, lt - 1);
  }
}

const int N = 1000;

class Solution {
public:
  int numDistinctRecu(string ss, string tt) {
    return recu(ss, tt, sz(ss), sz(tt));    
  }

  int numDistinctDP(string ss, string tt) {
    int a, b;
    a = sz(ss), b = sz(tt);
    if (b > a) return 0;

    int dp[a + 1][b + 1]; mst(dp, 0);

    fori (i, 0, a + 1) {
      fori (j, 0, b + 1) {

        if (i == 0 && j == 0)
          dp[i][j] = 1;

        else if (i == 0)
          dp[i][j] = 0;

        else if (j == 0) 
          dp[i][j] = 1;

        else if (ss[i-1] == tt[j-1])
          dp[i][j] = dp[i-1][j] + dp[i-1][j-1];

        else if (ss[i-1] != tt[j-1])
          dp[i][j] = dp[i-1][j];
      }
    }

    return dp[a][b];
  }

  int numDistinct(string ss, string tt) {
    srand(time(0));
    int x = rand(); 
    if (x % 2) 
      return numDistinctRecu(ss, tt);
    else
    return numDistinctDP(ss, tt);
  }
};

void test(string ss, string tt) {
  Solution go;
  cout << go.numDistinct(ss, tt) << "\n";
}

int main() {
   test("rabbbit", "rabbit");
  test("babgbag", "bag");
  return 0;
}
