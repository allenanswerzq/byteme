#include<bits/stdc++.h>
using namespace std;

bool validator(string& a) {
  stack<int> stk;
  for (auto c : a) {
    if (c=='[' || c=='(' || c=='{')
      stk.push(c);
    else {
      char ch = stk.top(); stk.pop();
      if ((ch=='{' && c=='}') ||
          (ch=='[' && c==']') ||
          (ch=='(' && c==')'))
          continue;
      return false;
    }
  }
  return true;
}

int main() {
  return 0;
}
