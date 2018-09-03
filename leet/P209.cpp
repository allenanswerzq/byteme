#include<bits/stdc++.h>
using namespace std;

// O(n) solution
// int minSubArrayLen(int s, vector<int>& nums) {
//   int sum = 0, start = 0;
//   int res = (1<<31)-1;
//   int n = nums.size();
//   for (int i=0; i<n; ++i) {
//     sum += nums[i];
//     while (sum >= s) {
//       res = min(res, i-start+1);
//       sum -= nums[start++];
//     }
//   } 
//   return res==(1<<31)-1 ? 0: res;
// }

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define fori(i, a, b) for(int i=(a); i<(b); ++i)

// O(nlogn)
int minSubArrayLen(int s, vector<int>& nums) {
  int n = nums.size();
  vector<int> pre_sum(n+1, 0);
  for (int i=1; i<=n; ++i)
  pre_sum[i] = pre_sum[i-1] + nums[i-1];

  int res = (1<<31) - 1;
  fori (i, 1, n + 1) {
  if (pre_sum[i] >= s) {
    int p = upper_bound(all(pre_sum), pre_sum[i] - s) - pre_sum.begin();
    if (p >= 0) res = min(res, i - (p - 1));  
  } 
  }
  return res == (1<<31)-1 ? 0 : res;
}

int main(int argc, char** argv) {
  vi aa = {2, 3, 1, 2, 4, 3};
  cout << minSubArrayLen(7, aa) << endl; 
  return 0;
}
