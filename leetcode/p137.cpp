#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& aa) {
    int ret = 0;
    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      for (auto x : aa) {
        sum += (x >> i) & 1;
      }
      if (sum % 3 == 1) 
        ret |= 1 << i;
      }
      return ret;
  }
};

int main() {
  return 0;
}
