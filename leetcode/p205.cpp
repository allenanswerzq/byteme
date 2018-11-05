#include <bits/stdc++.h>
using namespace std;

#define mst(x, a) memset(x, a, sizeof(x))

class Solution {
public:
  bool isIsomorphic(string ss, string tt) {
    int aa[256];
    int bb[256];
    mst(aa, 0);
    mst(bb, 0);
    for (int i=0; i<ss.size(); ++i) {
      if (!aa.count(ss[i]) && !bb.count(tt[i]) ) {
        aa[ss[i]] = tt[i];
        bb[tt[i]] = ss[i];
      } else {
        if (aa[ss[i]] != tt[i] || bb[tt[i]] != ss[i]) 
          return false; 
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
