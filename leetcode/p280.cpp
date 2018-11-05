#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array nums, reorder it in-place such that 
// nums[0] <= nums[1] >= nums[2] <= nums[3]....
// For example, given nums = [3, 5, 2, 1, 6, 4], 
// one possible answer is [1, 6, 2, 5, 3, 4]

#define all(x) (x).begin(), (x).end()

class Solution {
public:
  void wiggleSort(vector<int>& aa) {
    sort(all(aa)); 
    if (aa.size() <= 2) return;
    for (int i = 2; i < aa.size(); i += 2) {
      swap(aa[i], aa[i - 1]);
    } 
  }
};

class Solution {
public:
  void wiggleSort(vector<int>& aa) {
    if (aa.size() <= 1) return; 
    for (int i = 1; i < aa.size(); ++i) {
      if (i % 2 == 1 && aa[i] < aa[i - 1]) 
        swap(aa[i], aa[i - 1]);
      
      if (i % 2 == 0 && aa[i] > aa[i - 1])
        swap(aa[i], aa[i - 1]);
    }
  }
};
