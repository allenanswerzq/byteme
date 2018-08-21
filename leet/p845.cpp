#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int longestMountain(vector<int>& inp) {
    int n = sz(inp);
    if (n < 3) return 0;
    int res = 0;
    fori(i, 1, n-1) {
      int l = 0;
      int k = i;
      while(k-1>=0 && inp[k] > inp[k-1]) {--k; ++l;}
      int r = 0;
      k = i;
      while(k+1<n && inp[k] < inp[k+1]) {++k; ++r;}
      if (l && r)
        res = max(res, l + r + 1);
    }    
    return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
