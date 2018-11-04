#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  int canCompleteCircuit(vi& gas, vi& cost) {
    int idx;    
    int n = gas.size();
    for (int i = 0; i < n; ++i) {
      idx = i;
      int total = gas[i];
      if (total < cost[i]) continue;

      // Note: gas station along a circular route.
      int cur = (i + 1) % n;
      int pre = idx;
      for (; cur != i; cur = (cur + 1) % n) {
        total = total - cost[pre] + gas[cur];
        if (total < cost[cur]) break;
        pre = cur;
      }
      if (cur == i) return idx;

    }
    return -1;
  }
};

int main() {
  return 0;
}
