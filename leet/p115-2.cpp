#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int recu(string s, string t, int ls, int lt) {
  if (ls == 0) return 0;
  if (lt == 0) return 1;
  if (s[ls-1] != t[lt-1]) {
  return recu(s, t, ls-1, lt);
  } else {
  return recu(s, t, ls-1, lt) + recu(s, t, ls-1, lt-1);
  }
}

const int N = 1000;

class Solution {
public:
  int numDistinctRecu(string s, string t) {
  return recu(s, t, sz(s), sz(t));    
  }

  int numDistinctDP(string s, string t) {
  int a, b;
  a = sz(s), b = sz(t);
  if (b > a) return 0;

  int dp[a+1][b+1];
  mst(dp, 0);

  fori(i, 0, a+1) {
  fori(j, 0, b+1) {

  if (i == 0 && j == 0)
    dp[i][j] = 1;

  else if (i == 0)
    dp[i][j] = 0;

  else if (j == 0) 
    dp[i][j] = 1;

  else if (s[i-1] == t[j-1])
    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];

  else if (s[i-1] != t[j-1])
    dp[i][j] = dp[i-1][j];
  }
  }

  // fori(i, 0, a+1) {
  //   fori(j, 0, b+1) 
  //     cout << dp[i][j] << " ";
  //   cout << "\n";
  // }

  return dp[a][b];
  }

  int numDistinct(string s, string t) {
  srand(time(0));
  int x = rand(); 
  if (x % 2) 
  return numDistinctRecu(s, t);
  else
  return numDistinctDP(s, t);
  }
};

void test(string s, string t) {
  Solution go;
  cout << go.numDistinct(s, t) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test("rabbbit", "rabbit");
  test("babgbag", "bag");
  return 0;
}
