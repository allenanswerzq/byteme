#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> ret;
    if (n == 0) {
      ret.push_back(0);
      return ret;
    }

    ret = grayCode(n - 1);
    int flag = 1 << (n - 1);
    int prev_size = ret.size();
    for (int i = (prev_size - 1); i >= 0; --i) {
      ret.push_back(flag | ret.at(i));
    }
    return ret;
  }
};

int main() {
  return 0;
}
