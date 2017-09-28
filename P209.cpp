#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

// O(n) solution
int minSubArrayLen(int s, vector<int>& nums) {
  int sum = 0, start = 0;
  int res = INT_MAX;
  int n = nums.size();
  for (int i=0; i<n; ++i) {
    sum += nums[i];
    while (sum >= s) {
      res = min(res, i-start+1);
      sum -= nums[start++];
    }
  } 
  return res==INT_MAX ? 0: res;
}

// O(nlogn)
// find fisrt element that greater than val in A
int upper_bound(vector<int>& A, int val) {
  int lo=0, hi=A.size();
  while (lo < hi) {
    int mid = lo + (hi - lo)/2;
    if (A[mid] <= val) 
      lo = mid+1;
    else
      hi = mid;
  }
  return lo;
}

int minSubArrayLen(int s, vector<int>& nums) {
  int n = nums.size();
  vector<int> sums(n+1, 0);
  for (int i=1; i<=n; ++i)
    sums[i] = sums[i-1] + nums[i-1];

  int res = INT_MAX;
  for (int i=1; i<=n; ++i)
   if (sums[i] >= s) {
     int p = upper_bound(sums, sums[i] - s);
     if (p >= 0) res = min(res, i-p+1);  
   } 
  return res;
}

int main(int argc, char** argv) {
    return 0;
}
