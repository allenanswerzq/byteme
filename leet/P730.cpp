#include<bits/stdc++.h>
using namespace std;




const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int mod = 1e9 + 7;
const int size = 1002;
// Note: same palindrome can only be counted once.
int dp[size][size];
class Solution {
public:
  int countPalindromicSubsequences(string inp) {
  int n = sz(inp);
  fori (d, 1, n + 1) {
  fori (i, 0, n - d + 1) {
  int j = i + d - 1;
  if (i == j) 
    dp[i][j] = 1;
  else if (inp[i] == inp[j]) {
    int lo = i + 1;
    int hi = j - 1;
    while (lo <= hi && inp[i] != inp[lo]) ++lo;
    while (lo <= hi && inp[j] != inp[hi]) --hi; 

    if (lo > hi) {
    // Case 1: there is no same character as inp[i] between [i, j].
    // Example: a....a  aba
    dp[i][j] = dp[i+1][j-1] * 2 + 2;
    } else if (lo == hi) {
    // Case 2: there is only one character as inp[i].
    // Example: a...a...a  aaa
    dp[i][j] = dp[i+1][j-1] * 2 + 1;
    } else {
    // Case 3: there are multiple characters as inp[i];
    // Example: a...a...a...a 
    // The second part is hard to understand.
    dp[i][j] = dp[i+1][j-1] * 2 - dp[lo + 1][hi - 1];
    }
  } else {
    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
  }
  dp[i][j] = (dp[i][j] % mod + mod) % mod;
  } 
  }
  return dp[0][n - 1];
  }
};

void test(string inp) {
  Solution go;
  int r = go.countPalindromicSubsequences(inp);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  test("aaa");
  test("bccb");
  test("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba");
  return 0;
}
