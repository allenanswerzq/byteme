#include <bits/stdc++.h>
using namespace std;

// Of course, TLE ;-(
int maximumProduct(vector<int>& A) {
  int res=INT_MIN;
  int n = A.size();
  for (int i=0; i<n; ++i)
    for (int j=i+1; j<n; ++j)
      for (int k=j+1; k<n; ++k)
        res = max(res, A[i]*A[j]*A[k]);
  return res;
}
// best sloution
int maximumProduct(vector<int>& A) {
  sort(A.begin(), A.end());
  int n = A.size();
  int res = A[n-1]*A[n-2]*A[n-3];
  //res = max(res, A[n-1]*A[n-2]*A[0]); // 
  res = max(res, A[n-1]*A[0]*A[1]);   //
  //res = max(res, A[2]*A[1]*A[0]);
  return res;
}

int main() {
  return 0;
}
