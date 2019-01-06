#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // solution 2
    // NOTE: auto variable
    // algorithm ***
    int subarraySum(vector<int>& a, int k) {
      map<int, int> M;
      M[0] = 1;
      int ans = 0, csum=0;
      for (int i : a) {
        csum += i;
        auto it = M.find(csum - k);
        if ( it != M.end() )
          ans += it->second;
        M[csum]++;
      }
      return ans;
    }
    int fun(int i, int j, vector<int>& a) {
      int ret = 0;
      for (int k=i; k<=j; ++k) {
        ret += a[k];
      }
      return ret;
    }
    // solution 1
    int subarraySum1(vector<int>& a, int k) {
      int n = a.size();
      int ans = 0;
      int sum[n][n];
      for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
          sum[i][j] = fun(i, j, a);
          if (sum[i][j] == k)
            ans++;
        }
      }
      return ans;
    }
};

int main(void) {
  return 0;
}
