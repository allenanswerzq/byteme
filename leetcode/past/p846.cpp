#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isNStraightHand(vector<int>& aa, int W) {
    multiset<int> st;
    fora (a, aa) st.insert(a);
    while (!st.empty()) {
      int cur = *st.begin();
      fori (i, cur, cur + W)  {
        if (st.count(i) == 0) return false;
        st.erase(st.find(i));
      }
    }
    return true;
  }
};

class Solution {
public:
  bool isNStraightHand(vector<int>& aa, int W) {
    map<int, int> mp;
    fora(a, aa) ++mp[a];
    if (sz(aa) % W) return false;
    while(!mp.empty()) {
      auto it = mp.begin();
      int cur = it->fi;
      fori(i, 0, W) {
        int tmp = cur + i;
        if (!mp.count(tmp)) {
          return false;
        } else {
          --mp[tmp];
          if (mp[tmp] == 0)
          mp.erase(tmp);
        }
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
