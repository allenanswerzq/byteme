#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

// TLE
// 182/183 test cases passed
int maxProduct(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n);
  dp[0] = nums[0];    
  for (int i=1; i<n; ++i) {
    int y = INT_MIN;
    for (int k=i; k>=0; --k) {
      int x = 1;
      for (int j=i; j>=k; --j)
        x *= nums[j];
      y  = max(y, x);
    }
    cout << y << endl;
    dp[i] = max(y, dp[i-1]); 
  }
  return dp[n-1];
}

// need review
int maxProduct(vector<int>& nums) {
  int res = nums[0];
  for (int i=1, x=res, y=res; i<n; ++i) {
    if (nums[i] < 0)
      swap(x, y);
    x = max(x, nums[i]*x);
    y = min(y, nums[i]*y);
    res = max(x, res);
  }
  return x;
}

int main(int argc, char** argv) {
  return 0;
}
