#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& A, int k) {
  int res = INT_MIN;
  int lo = 0, hi = k-1;
  for(; hi<A.size(); ++lo,++hi) {
    int sum = 0;
    for (int k=lo; k<=hi; ++k)
      sum += A[k];
    res = max(res, sum);
  }
  return (double)res / k;
}

int main() {
  return 0;
}
