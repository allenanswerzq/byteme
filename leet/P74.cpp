#include<bits/stdc++.h>
using namespace std;

// binary search
// Accepted
bool searchMatrix(vector<vector<int>>& aa, int target) {
  int m = aa.size();
  if(m == 0) return false;
  int n = aa[0].size();
  int lo = 0, hi = m * n - 1;
  while(lo <= hi) {
    int mid = lo + (hi-lo)/2;
    int med = aa[mid / n][mid % n];
    if (med == target) return true;
    else if (med > target) hi = mid - 1;
    else lo = mid + 1;
  }
  return false;
}

int main(int argc, char** argv) {
  return 0;
}
