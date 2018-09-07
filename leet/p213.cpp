#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int robber(vector<int>& aa, int lo, int hi) {
    int pre = 0, cur = 0;
    for (int i = lo; i <= hi; ++i) {
      int t = max(pre + aa[i], cur);
      pre = cur;
      cur = t;
    }
    return cur;
  }

  int rob(vector<int>& aa) {
    int n = aa.size();
    if (n < 2) return n ? aa[0] : 0;
    return max(robber(aa, 0, n - 2), robber(aa, 1, n - 1)); 
  }
};

int main(int argc, char** argv) {
  return 0;
}
