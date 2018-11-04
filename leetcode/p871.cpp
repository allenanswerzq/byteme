#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vvi& aa) {
    int n = sz(aa);
    int d = startFuel;
    int res = 0;
    int k = 0;
    multiset<int> st;
    while (d < target) {
      while (k < n && aa[k][0] <= d) {
        st.insert(aa[k][1]);
        ++k;
      }
      if (sz(st) == 0) return -1;
      d += *(prev(st.end()));
      st.erase(prev(st.end()));
      ++res;
    }
    return res;
  }
};

int main() {
  return 0;
}
