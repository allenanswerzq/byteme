#include<bits/stdc++.h>
using namespace std;

// Transform original problem into a cycle detection problem
// define f(i) = A[i] maps domain into itself
// if i != j such that f(i) == f(i)
// then A[i] is the answer
int findDuplicate(vector<int>& nums) {
    
}

#define vi vector<int>
class Solution {
public:
  int findDuplicate(vi& aa) {
    int lo = 1, hi = sz(aa) - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      int cnt = 0;
      for (auto &a: aa)
        if (a <= mid) ++cnt;
      if (cnt <= mid) lo = mid + 1;
      else hi = mid;
    }
    return lo;
  }
};

int main(int argc, char** argv) {
  return 0;
}
