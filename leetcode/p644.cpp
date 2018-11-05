#include <bits/stdc++.h>
using namespace std;

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
     
}

int main() {
  return 0;
}
