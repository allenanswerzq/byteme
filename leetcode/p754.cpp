#include<bits/stdc++.h>
using namespace std;

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
