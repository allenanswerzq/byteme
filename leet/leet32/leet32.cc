/* created   : 2022-05-02 22:31:08
 * accepted  : 2022-05-02 22:31:08
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  int longestValidParentheses(string S) {
    int ans = 0;
    vector<int> stk;
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == '(') {
        stk.push_back(i);
      }
      else {
        if (stk.size() && S[stk.back()] == '(') {
          stk.pop_back();
          ans = max(ans, i - (stk.size() ? stk.back() : -1));
        }
        else {
          // Start a new substring
          stk.push_back(i);
        }
      }
    }
    return ans;
  }
};
