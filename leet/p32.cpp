#include<bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  int longestValidParentheses(string ss) {
  int res = 0;
  int lo = 0;
  deque<int> dq;
  for (int i = 0; i < ss.size(); ++i) {
    if (ss[i] == '(') dq.push_back(i);
    else {
    if (dq.empty()) lo = i + 1;
    else {
      dq.pop_back();
      res = dq.empty() ? max(res, i - lo + 1) 
               : max(res, i - dq.back());
    }
    }
  }
   return res;
  }
};

void test(string aa) {
  Solution go;
  int r = go.longestValidParentheses(aa);
  cout << r << endl;
}

int main() {
  test("(()");
  test("((())()");
  return 0;
}
