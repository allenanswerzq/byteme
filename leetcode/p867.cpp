#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>>& aa) {
  int m = sz(aa), n = sz(aa[0]);
  vvi res (n, vi(m, 0));
  fori (i, 0, n) {
    fori (j, 0, m) 
    res[i][j] = aa[j][i];
  } 
  return res;
  }
};


int main() {
 

  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  
  return 0;
}
