#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t r = 0;        
    for (int i = 0; i < 32; ++i) {
      uint32_t p = (n >> i) & 1;
      r = r | (p << (31 - i));
    }
    return r;
  }
};

int main() {
  cout << reverseBits(43261596) << endl;
  return 0;
}
