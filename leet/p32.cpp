#include<bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  int longestValidParentheses(string ss) {
    int n = ss.size();
    int ret = 0;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int j = i - 2 - dp[i - 1];
      if (ss[i - 1] == '(' || j < 0 || ss[j] == ')') dp[i] = 0;
      else {
        dp[i] = dp[i - 1] + 2 + dp[j];
        ret = max(ret, dp[i]);
      }
   }
   return ret;
  }
};

int main() {
	test("(()");
	test("((())()");
	return 0;
}
