#include<bits/stdc++.h>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
  int lo, hi, mid, r;
  lo = 1, hi = n;
  r = -1;
  mid = 0;
  while (r != 0) {
    mid = lo + (hi - lo) / 2;
    r = guess(mid); 
    // cout << mid << " " << r << "\n";
    if (r == -1) {
    hi = mid - 1; 
    } else if (r == 1)
    lo = mid + 1;
  }
  return mid;
  }
};

int main() {
   return 0;
}
