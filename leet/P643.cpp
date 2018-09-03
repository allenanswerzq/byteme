#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

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

int main(int argc, char** argv) {
  return 0;
}
