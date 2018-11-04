#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  vector<int> getRow(int n) {
    if (n == 0) return {1};
    vi ret(n + 1, 1);
    vi tmp(n + 1, 1);
    for (int i = 2; i < n; ++i) {
      for (int k = 0; k < i - 1; ++k)
        tmp[k + 1] = ret[k] + ret[k + 1]; 
      tmp[0] = 1;
      tmp[i] = 1;
      ret = tmp;
    }
    return ret;
  }

  vector<int> getRow2(int n) {
    vi ret(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
      for (int k = i - 1; k >= 1; --k)
        ret[k] += ret[k-1];
    }
    return ret;
  }
};

int main() {
  return 0;
}
