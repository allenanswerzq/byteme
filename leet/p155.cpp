#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {
    minValue = INT_MAX; 
  }
  
  void push(int x) {
    minValue = min(minValue, x);
    dp.push_back(minValue);
    stk.push_back(x);
  }
  
  void pop() {
    stk.pop_back();
    dp.pop_back();
    minValue = stk.empty() ? INT_MAX : dp.back();
  }
  
  int top() {
    if (stk.size())
      return stk.back();
    return -1;
  }
  
  int getMin() {
    if (dp.size())
      return dp.back(); 
    return -1;
  }
private:
  int minValue;
  vector<int> stk;
  vector<int> dp;
};

int main(int argc, char** argv) {
  return 0;
}
