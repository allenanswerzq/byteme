#include<bits/stdc++.h>
using namespace std;

// TODO
class Solution {
  int uniqueLetterString(string S) {
  int n = S.size();
  int mod = 1000000007;
  ll ret = 0;
  for(int i = 0; i < n; i++) {
  int l = i-1;
  for(; l >= 0 && s[l] != s[i]; l--);
  int r = i+1;
  for(; r < n && s[r] != s[i]; r++);
  ret += (ll)(r - i) * (i - l);
  }
  return (int)(ret % mod);
  }
} 
