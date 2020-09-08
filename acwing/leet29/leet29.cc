/* created   : 2020-09-08 23:39:57
 * accepted  : 2020-09-08 23:40:00
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// NOTE: Copied form leetcode website.

//#define HALF_INT_MIN -1073741824
#define HALF_INT_MIN (INT_MIN >> 1)
class Solution {
public:
  int divide(int dividend, int divisor) {

    // return bruteForce(dividend, divisor);
    // return logSquareofnSolnWithO1space(dividend, divisor);
    return optimalSolnWithRighShiftOperator(dividend, divisor);
    // return divide2(dividend, divisor);
  }

  int optimalSolnWithRighShiftOperator(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;
    // Handle everything as -ve
    int sign = -1;

    if (dividend > 0) {
      dividend = -dividend;
      sign = -sign;
    }
    if (divisor > 0) {
      divisor = -divisor;
      sign = -sign;
    }

    int highestDouble = divisor;
    int powerOf2 = -1;

    while (highestDouble >= HALF_INT_MIN && (highestDouble + highestDouble) >= dividend) {
      highestDouble = highestDouble + highestDouble;
      powerOf2 = powerOf2 + powerOf2;
    }

    int quotient = 0;
    while (dividend <= divisor) {
      if (dividend <= highestDouble) {
        quotient = quotient + powerOf2;
        dividend = dividend - highestDouble;
      }
      highestDouble = highestDouble >> 1;
      powerOf2 = powerOf2 >> 1;
    }

    if (sign == -1)
      return -quotient;
    else
      return quotient;
  }

  int logSquareofnSolnWithO1space(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;

    // Handle everything in -ve so start with negative
    int sign = -1;
    if (dividend > 0) {
      sign = -sign;
      dividend = -dividend;
    }

    if (divisor > 0) {
      sign = -sign;
      divisor = -divisor;
    }

    int quotient = 0;
    while (dividend <= divisor) {
      /* We know it'll fit at least once as divivend >= divisor.
       * Note: We use a negative powerOfTwo as it's possible we
       *  might havethe case divide(INT_MIN, -1). */
      int powerOfTwo = -1;
      int value = divisor;

      while (value >= HALF_INT_MIN && value + value >= dividend) {
        value = value + value;
        powerOfTwo = powerOfTwo + powerOfTwo;
      }
      quotient = quotient + powerOfTwo;
      dividend = dividend - value;
    }

    // If both dividend and divisor are negative/positive, sign == -1, so make
    // quotient positive. else return quotient
    if (sign == -1)
      return -quotient;
    else
      return quotient;
  }

  int bruteForce(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;

    // Handle everything in -ve so start with negative
    int sign = -1;
    if (dividend > 0) {
      sign = -sign;
      dividend = -dividend;
    }

    if (divisor > 0) {
      sign = -sign;
      divisor = -divisor;
    }

    // count how many times divisor has to be added to get diviend
    int quotient = 0;
    while (dividend <= divisor) {
      dividend = dividend - divisor;
      quotient -= 1;
    }

    // If both dividend and divisor are negative/positive, sign == -1, so make
    // quotient positive. else return quotient
    if (sign == -1)
      return -quotient;
    else
      return quotient;
  }
};

void solve() {}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
