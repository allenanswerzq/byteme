#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& A) {
    int n = sz(A);
    fori (i, 0, n - 1) {
      if (A[i] > A[i+1]) return i;
    }
    return -1;
  }
};

int main() {
  return 0;
}
