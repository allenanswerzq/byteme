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

int threeSumSmaller(vector<int>& nums, int target) {
  int n = nums.size();
  int ret = 0;
  sort(nums.begin(), nums.end());
  for (int i=0; i < n - 2; ++i){
  int lo = i + 1;
  int hi = n - 1; 
  while (lo < hi) {
  if (nums[i] + nums[lo] + nums[hi] < target) {
  ret += hi - lo;
  ++lo;
  } else {
  --hi;
  }
  }
  }
  return ret;
}

#define vi vector<int>

int main(int argc, char** argv) {
  vi aa = {-2, 0, 1, 3};
  int res = threeSumSmaller(aa, 2);
  cout << res << endl;
  return 0;
}
