#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string ss) {
    map<char, int> mp;
    int n = sz(ss);
    // Find maximum index for each characters
    for (int i=0; i<n; ++i) mp[ss[i]] = i;
    vector<int> ret;
    int i = 0;
    while (i < n) {
      int x = mp[ss[i]];
      int k = i;
      for (k=i; k<x; k++) {
        if (mp[ss[k]] > x) x = mp[ss[k]];
      }
      ret.pb(x-i+1);
      i = k+1;
    }
    return ret;
  }
};
