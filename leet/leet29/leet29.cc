/* created   : 2020-09-08 23:39:57
 * accepted  : 2020-09-08 23:40:00
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

#define HALF_MIN (INT_MIN >> 1)
class Solution {
 public:
  int divide(int A, int B) {
    if (A == INT_MIN && B == -1) {
      return INT_MAX;
    }
    if (A == INT_MIN && B == 1) {
      return INT_MIN;
    }
    int sign = ((A > 0) ^ (B > 0)) ? -1 : 1;
    if (A > 0) A = -A;
    if (B > 0) B = -B;
    int ans = 0;
    while (A <= B) {
      int t = B;
      int n = 0;
      while (t >= HALF_MIN && t + t >= A) {
        // B 2B 4B 8B
        t = t + t;
        n++;
      }
      ans += (1 << n);
      A -= t;
    }
    if (sign == -1) {
      return -ans;
    } else {
      return ans;
    }
  }
};

class Solution {
public:
  int divide(int A, int B) {
    if (B == 1) return A;
    if (B == -1) return (A == INT_MIN ? INT_MAX : -A);
    if (B == INT_MIN) return (A == INT_MIN ? 1 : 0);
    int sign = (A > 0) ^ (B > 0) ? -1 : 1;
    int ans = 0;
    if (B < 0) B = -B;
    if (A < 0) {
      A += B;
      ans += (A < 0 ? sign : 0);
      A = -A;
    }
    // -10 / -11
    // -10 / 2
    // A - (b+2b+4b+8b..+) = A - (2^n - 1)b > 0
    int t = B;
    int cnt = sign;
    while (A >= t) {
      ans += cnt;
      A -= t;
      // A >= t + t
      if (A - t < t) break;
      t += t;
      cnt += cnt;
    }
    while (A >= B) {
      ans += sign;
      A -= B;
    }
    return ans;
  }
};
