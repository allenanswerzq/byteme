#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// brute force approch
// but it wroked
double findMaxAverage(vector<int>& A, int k) {
  double mx = INT_MIN;
  vector<int> sum(A.size()+1);

  for (int i=1; i<=A.size(); ++i) 
  sum[i] = sum[i-1] + A[i-1];

  for (int i=0; i<=A.size()-k; ++i) {
  for (int j=k; i+j<=A.size(); ++j) {
    if (sum[i+j]-sum[i] > mx*j) 
    // Note: mutiply by 1.0 or change sum type to double
    mx = 1.0*(sum[i+j]-sum[i])/j;
  }
  }
  return mx;
}

// binary search approach
double findMaxAverage(vector<int>& A, int k) {
  int lo=-10000, hi=10000;
  while (h-l > 1e5) {
  double mid = lo + (hi-lo)/2;
  if (isgreater(A, mid, k)) {
    hi = mid;
  } else {
    lo = mid;
  }
  }        
  return mid;
}

int main(int argc, char** argv) {
  return 0;
}
