#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int count(int inp) {
  // Choose first number can only has 9 choices,
  // since leading zero is an invalid number.
  int res = 9; 
  int nine = 9;
  // Basic combination problem.
  fori (i, 1, inp) {
  res = res * nine;
  --nine;
  } 
  return res;
}

class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
  if (n == 0) return 1;
  int dp[n + 1];
  dp[1] = 10;
  fori (i, 2, n+1) {
    dp[i] = dp[i-1] + count(i);
  }
  return dp[n];
  }
};

int test(int n) {
  Solution go;
  int x = go.countNumbersWithUniqueDigits(n);
  cout << x << "\n";
  return x;
}

int main() {
   test(1);
  test(2);
  test(3);
  return 0;
}
