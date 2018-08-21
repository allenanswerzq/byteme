#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int recu(string s) {
  int n = sz(s);
  if (n == 0) return 1;
  if (s[0] == '0') return 0;
  if (n == 1) return 1;
  int res = 0;
  int x = stoi(s.substr(0, 2));
  if (1 <= x && x <= 26)
    res += recu(s.substr(2));
  res += recu(s.substr(1));
  return res;
}

class Solution {
public:
  int numDecodingsRecu(string s) {
    return recu(s);
  }

  int numDecodingsDP(string s) {
    int n = sz(s);
    if (s[0] == '0') return 0;
    if (n == 1) return 1;
    int dp[n+1]; mst(dp, 0);
    dp[0] = 1;
    dp[1] = 1;
    fori (i, 2, n+1) {
      int j = i - 1;
      if (s[j] != '0')
        dp[i] += dp[i-1]; 
      
      if (s[j-1] != '0') {
        int x = stoi(s.substr(j-1, 2));
        if (1 <= x && x <= 26)
          dp[i] += dp[i-2];
      }
    }
    return dp[n];
  }

  int numDecodings(string s) {
    // return numDecodingsRecu(s);
    return numDecodingsDP(s);
  }

};

void TEST(string s) {
  Solution go;
  cout << go.numDecodings(s) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  TEST("0");
  TEST("120");
  TEST("102");
  TEST("12");
  TEST("226");
  return 0;
}
