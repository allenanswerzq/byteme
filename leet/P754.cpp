#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Proof: 
// 1 + 2 + 3 + 4 + ... + k = sum
// assume we filp x to -x 
// then sum - 2x = target
// so x = (sum - target) / 2
int reachNumber(int target) {
  target = abs(target)
  int k = 0;
  int sum = 0;
  while (true) {
    if (sum>=target && (sum-target)%2==0)
      return k;
    k++;
    sum += k;
  }
  return -1;
}
