#include<bits/stdc++.h>
using namespace std;
// Ref: https://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/

int keyboardRecu(int n) {
  if (n <= 6) return n;
  int res = 0;
  ford (i, n-3, 0) {
    // If we use `ith` position as ctrl-a, then ctrl-c, ctrl-v, ctrl-v...
    res = max(res, keyboardRecu(i) * (n - i - 1));
  }
  return res;
}

int keyboardDP(int n) {
  if (n <= 6) return n;
  // dp[i] denotes the maximum value that can get from 1...i
  int dp[n + 1];
  mst(dp, 0);

  fori (i, 1, n+1) {
    if (i <= 6) {
      dp[i] = i;
    } else {
      dp[i] = 0;
      ford (j, i - 3, 0) {
      dp[i] = max(dp[i], dp[j] * (i - j - 1));
      }
    }
  }
  return dp[n];
}

class Solution {
public:
  int keyboard4(int n) {
    // return keyboardRecu(n);
    return keyboardDP(n);
  }
};

void test(int n) {
  Solution go;
  int r = go.keyboard4(n);
  output(r);
}

int main() {
  fori (i, 1, 20) test(i);
  return 0;
}
