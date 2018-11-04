#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
  return a[1] < b[1];
}

class Solution {
public:
  int intersectionSizeTwo(vvi& aa) {
    sort(aa.begin(), aa.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
    });

    set<int> ret;
    int n = aa.size();
    fori (i, 0, n) {
      int cnt = 0;
      for (auto it: ret) {
        if (it >= aa[i][0] && it <= aa[i][1]) cnt++;
        if (cnt >= 2) break;
      }
      int last = aa[i][1];
      while (cnt < 2) {
        // Note: we must check this
        if (!ret.count(last)) {
          ret.insert(last);
          cnt++;
        }
        --last;
      }
    }
    return ret.size();
  }
};
