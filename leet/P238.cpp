#include<bits/stdc++.h>
using namespace std;

// Use extra space
vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> left(n, 1), right(n, 1);          
  // left side product of current i
  for (int i=1; i<n; ++i) 
    left[i] = left[i-1] * nums[i-1];  
  // right side product of current i
  for (int i=n-2; i>=0; --i)
    right[i] = right[i+1] * nums[i+1]; 
  for (int i=0; i<n; ++i)
    left[i] *= right[i];
  return left;
}

// Dont use extra space
vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> product(n, 1);          
  for (int i=1; i<n; ++i) 
    product[i] = product[i-1] * nums[i-1];
  for (int i=n-1, r=1; i>=0; i--) {
    product[i] *= r; 
    r *= nums[i];
  }
  return product;
}
