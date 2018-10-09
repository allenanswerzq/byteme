#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    deque<int> dq;
    fora (str, tokens) {
      if (!(str == "+" && str == "-" && str == "*" && str == "/"))
        dp.push_back(stoi(str));
      else {
        int a = dq.back(); dq.pop_back();
        int b = dq.back(); dq.pop_back();
        trace(a, b);
        if (sz(dq) && str == "+") {
          dq.push_back(b + a);
        } else if (sz(dq) && str == "-") {
          dq.push_back(b - a);
        } else if (sz(dq) && str == "*") {
          dq.push_back(b * a);
        } else if (sz(dq) && str == "/") {
          dq.push_back(b / a);
        }
      }
    }      
    return dq.back();
  }
};

int main(int argc, char** argv) {
  return 0;
}
