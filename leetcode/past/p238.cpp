#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& aa) {
    int n = aa.size();
    vector<int> left(n, 1), right(n, 1);          

    // Left side product of current i
    for (int i = 1; i < n; ++i) 
      left[i] = left[i-1] * aa[i-1];  

    // Right side product of current i
    for (int i = n-2; i >= 0; --i)
      right[i] = right[i+1] * aa[i+1]; 

    for (int i = 0; i < n; ++i)
      left[i] *= right[i];
    return left;
  }

  vector<int> productExceptSelf(vector<int>& aa) {
    int n = aa.size();
    vector<int> ret(n, 1);          
    
    for (int i = 1; i < n; ++i) 
      ret[i] = ret[i-1] * aa[i-1];

    for (int i = n-1, r = 1; i >= 0; i--) {
      ret[i] *= r; 
      r *= aa[i];
    }
    return ret;
  }
};
