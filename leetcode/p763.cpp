#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string S) {
      map<char, int> mp;      
      int n = SZ(S);
      // find maximum index for each characters
      for (int i=0; i<n; ++i) mp[S[i]] = i;
      vector<int> ret;    
      int i = 0;
      while (i < n) {
        int x = mp[S[i]]; 
        int k = i;
        for (k=i; k<x; k++) {
          if (mp[S[k]] > x) x = mp[S[k]];   
        }
        ret.PB(x-i+1);
        i = k+1;
      }
      return ret;
  }
};
