#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& A) {
  int n = sz(A);
  fori(i, 0, n-1) {
  if (A[i] > A[i+1]) 
  return i;
  }      
  return -1;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
