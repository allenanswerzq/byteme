#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  int minRefuelStops(int target, int startFuel, vvi& aa) {
  int n = sz(aa);
  int d = startFuel;
  int res = 0;
  int k = 0;
  multiset<int> mst;
  while (d < target) {
    while (k < n && aa[k][0] <= d) {
    mst.insert(aa[k][1]);
    ++k;
    }
    if (sz(mst) == 0) return -1;
    d += *(prev(mst.end()));
    mst.erase(prev(mst.end()));
    ++res;
  } 
  return res;
  }
};

int main() {
   return 0;
}
