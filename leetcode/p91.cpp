#include <bits/stdc++.h>
using namespace std;

int recu(string ss) {
  int n = sz(ss);
  if (n == 0) return 1;
  if (ss[0] == '0') return 0;
  if (n == 1) return 1;
  
  int res = 0;
  int x = stoi(ss.substr(0, 2));
  if (1 <= x && x <= 26) 
    res += recu(ss.substr(2));
  res += recu(ss.substr(1));
  return res;
}

class Solution {
public:
  int numDecodingsRecu(string ss) {
    return recu(ss);
  }

  int numDecodingsDP(string ss) {
    int n = sz(ss);
    if (ss[0] == '0') return 0;
    if (n == 1) return 1;
    int dp[n + 1]; mst(dp, 0);
    dp[0] = 1; 
    dp[1] = 1;
    fori (i, 2, n + 1) {
      int j = i - 1;
      if (ss[j] != '0')
        dp[i] += dp[i-1]; 
      
      if (ss[j - 1] != '0') {
        int x = stoi(ss.substr(j-1, 2));
        if (1 <= x && x <= 26)
          dp[i] += dp[i-2];
      }
    }
    return dp[n];
  }

  int numDecodings(string ss) {
    return numDecodingsRecu(ss);
    return numDecodingsDP(ss);
  }

};

void test(string ss) {
  Solution go;
  cout << go.numDecodings(ss) << "\n";
}

int main() {
   test("0");
  test("120");
  test("102");
  test("12");
  test("226");
  return 0;
}
