#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

int findLengthOfLCIS(vector<int>& nums) {
  int n = nums.size();
  if (n <= 0) return 0;
  int res = INT_MIN; // dont need so small zero is just fine
  int k = 1;
  for (int i=1; i<n; ++i) { 
    if (nums[i] > nums[i-1]) k++;
    else k = 1;
    res = max(res, k); 
  }
  return res;
}

int findLengthOfLCIS(vector<int>& nums) {
  int len = 0;
  int ma = 0;
  for (int i=0; i<nums.size(); ++i) {
    if (i==0 || nums[i]>nums[i-1])
      len++;
    else
      len = 1;
    ma = max(len, ma);
  }
  return ma;
}

int main(int argc, char** argv) {
    return 0;
}
