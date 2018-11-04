#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& aa) { 
    unordered_set<int> st(aa.begin(), aa.end());         
    int ret = 0;
    for (auto x : st) {
      if (!st.count(x - 1)) {
        int y = x + 1;
        while (st.count(y)) ++y;
        ret = max(ret, y - x);
      }
    }
    return ret;
  }

  int longestConsecutive(vector<int>& aa) { 
    unordered_map<int, int> m;
    int best = 0;
    for (auto x : aa) {
      if (m.find(x) == m.end()) {
        int l = m.find(x - 1) == m.end() ? 0 : m[x - 1];
        int r = m.find(x + 1) == m.end() ? 0 : m[x + 1];
        int sum = l + r + 1;
        best = max(best, sum);
        m[x] = sum;
        m[x - l] = sum;
        m[x + r] = sum;
      } 
    }
    return best;
  }
};

int main() {
  return 0;
}
