#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

int triangleNumber(vector<int>& A) {
  int n = A.size();
  int cnt = 0;
  for (int i=0; i<n; ++i)   
    for (int j=i+1; j<n; ++j) 
      for (int k=j+1; k<n; ++k)
        if (A[i] + A[j]>A[k] && A[i]-A[j]<A[k])
          cnt++;
  return cnt;

}

// find first greater equal pos
// means lower_bound
int firstGe(vector<int>& A, int target) {
  sort(A.begin(), A.end());
  int lo, hi;
  lo = 0, hi = A.size()-1;
  while (lo < hi) {
    cout << lo << " " << hi << endl;
    int mid = lo + (hi-lo)/2;
    // <= first greater pos
    // <  first greater equal pos
    if (A[mid] < target) 
      lo = mid + 1;
    else 
      hi = mid;
  }
  return lo;
}

int main() {
  int n = 3;
  if (argc > 1)
    n = atoi(argv[1]);
  int a[] = {1, 2, 5, 8, 10};
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  printVector(v);
  cout << "LOWER: " << n << endl;
  cout << firstGe1(v, n) << endl;
  return 0;
}
