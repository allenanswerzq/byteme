#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

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
