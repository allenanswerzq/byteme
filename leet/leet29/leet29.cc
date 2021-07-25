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

void solve() {}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
