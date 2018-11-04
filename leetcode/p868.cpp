#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  int binaryGap(int aa) {
  int res = 0;
  int lo, hi;
  lo = -1;
  hi = 0;
  while (aa) {
    if (aa & 1) {
    if (lo == -1) lo = hi; 
    else {
      res = max(res, hi - lo);
      lo = hi;
    }
    }
    ++hi;
    aa >>= 1;
  }     
  return res;
  }
};

int main() {
 
  Solution go;
  // int aa = 22;
  // int aa = 5;
  // int aa = 6;
  int aa = 8;
  cout << go.binaryGap(aa) << endl;
  return 0;
}
