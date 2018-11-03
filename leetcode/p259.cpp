#include<bits/stdc++.h>
using namespace std;

// Given an array of n integers nums and a target, 
// find the number of index triplets i, j, k with 0 <= i < j < k < n that 
// satisfy the condition nums[i] + nums[j] + nums[k] < target.
// For example, given nums = [-2, 0, 1, 3], and target = 2.
// Return 2. Because there are two triplets which sums are less than 2:
// [-2, 0, 1]
// [-2, 0, 3]
// Follow up:
// Could you solve it in O(n2) runtime?

// Idea: After sorted, if i, j, k is a valid triple
// then (i, j, j+1), (i, j, j+2), ..., (i, j, k-1), (i, j, k) are also valid triples

#define vi vector<int>

class Solution {
public:
  int threeSumSmaller(vector<int>& aa, int target) {
    int n = aa.size();
    int ret = 0;
    sort(aa.begin(), aa.end());
    for (int i = 0; i < n - 2; ++i){
      int lo = i + 1, hi = n - 1; 
      while (lo < hi) {
        if (aa[i] + aa[lo] + aa[hi] < target) {
          ret += hi - lo;
          ++lo;
        } else {
          --hi;
        }
      }
    }
    return ret;
  }
};

void test(vi aa, int kk) {
  Solution go;
  int ret = go.threeSumSmaller(aa, kk); 
  output(1, ret);
}

int main(int argc, char** argv) {
  test({-2, 0, 1, 3}, 2);
  return 0;
}
