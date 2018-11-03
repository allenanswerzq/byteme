#include<bits/stdc++.h>

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& aa, int k) {
    map<int, int> mp;
    for (int i = 0; i < aa.size(); ++i)
      if (mp.count(aa[i]) && i - mp[aa[i]] <= k)
        return true;
      else
        mp[aa[i]] = i;
    return false;
  }
};
