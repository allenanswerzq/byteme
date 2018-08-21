#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
