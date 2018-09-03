#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

int findMin(vector<int>& nums) {
  int n = nums.size();
  int lo=0, hi=n-1;
  int res = INT_MAX;
  while (lo <= hi) {
    int mid = lo + (hi-lo)/2;
    if (nums[lo] <= nums[mid]) {
      res = min(nums[lo], res);
      lo = mid+1;
    } else {
      res = min(res, num[mid]);
      hi = mid-1; 
    }
  }    
  return res;
}

int main(int argc, char** argv) {
  return 0;
}
