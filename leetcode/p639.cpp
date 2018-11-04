#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int recu(string s, int ix) {
  if (ix < 0) return 1;

  int res = 0;
  if (s[ix] == '*') {
  res = 9 * recu(s, ix-1) % mod;
  if (ix > 0 && s[ix-1] == '1')
    res = (res + 9 * recu(s, ix-2)) % mod;

  else if (ix > 0 && s[ix-1] == '2')
    res = (res + 6 * recu(s, ix-2)) % mod;

  else if (ix > 0 && s[ix-1] == '*')
    res = (res + 15 * recu(s, ix-2)) % mod;

  } else {
    if (s[ix] != '0')
      res = (res + recu(s, ix-1)) % mod;

    if (ix > 0 && s[ix-1] == '1')
      res = (res + recu(s, ix-2)) % mod;

    else if (ix > 0 && s[ix-1] == '2' && s[ix] <= '6')
      res = (res + recu(s, ix-2)) % mod;

    else if (ix > 0 && s[ix-1] == '*') {
      // ...*[0-6]
      if (s[ix] <= '6')
      res = (res + 2 * recu(s, ix-2)) % mod;
      else
      res = (res + recu(s, ix-2)) % mod;
    }
  }
  return res;
}

int numDecodingsDP(string s) {
  int n = sz(s);
  if (n == 0) return 0;
  if (s[0] == '0') return 0;

  int dp[n + 1];
  mst(dp, 0);
  dp[0] = 1;
  dp[1] = s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1;
  fori (i, 2, n+1) {
    int j = i - 1;

    if (s[j] == '*') {
      dp[i] = 9 * dp[i - 1];

      if (j > 0 && s[j - 1] == '1')
      dp[i] = (dp[i] + 9 * dp[i - 2]) % mod;

      else if (j > 0 && s[j - 1] == '2')
      dp[i] = (dp[i] + 6 * dp[i - 2]) % mod;

      else if (j > 0 && s[j - 1] == '*')
      dp[i] = (dp[i] + 15 * dp[i - 2]) % mod;

    } else {

      if (s[j] != '0')
      dp[i] = dp[i-1];

      if (j > 0 && s[j - 1] == '1')
      dp[i] = (dp[i] + dp[i - 2]) % mod;

      else if (j > 0 && s[j - 1] == '2' && s[j] <= '6')
      dp[i] = (dp[i] + dp[i - 2]) % mod;

      else if (j > 0 && s[j - 1] == '*') {
      if (s[j] <= '6')
        dp[i] = (dp[i] + 2 * dp[i - 2]) % mod;
      else
        dp[i] = (dp[i] + dp[i - 2]) % mod;
      }
    }
  }
  return dp[n];;
}

class Solution {
public:
  int numDecodings(string s) {
    // return recu(s, sz(s)-1);
    return numDecodingsDP(s);
  }
};

void test(string s) {
  Solution go;
  cout << go.numDecodings(s) << "\n";
}

int main() {
  test("0");
  test("*");
  test("1*");
  test("226");
  test("*09");
  test("10*9");
  test("***");
  test("*12");
  test("*********");
  test("**********1111111111");
  return 0;
}
