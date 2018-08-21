#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

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
  string a = "{[]()}";
  cout << validator(a) << '\n';
}
