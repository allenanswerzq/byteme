/* created   : 2022-05-23 21:25:48
 * accepted  : 2022-05-23 21:25:49
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  const int M = 214748364;
  int myAtoi(string S) {
    int n = S.size();
    int i = 0;
    while (i < n && S[i] == ' ') i++;
    int ans = 0;
    int sign = 1;
    if (i < n && (S[i] == '+' || S[i] == '-')) {
      sign = (S[i] == '+') ? 1 : -1;
      i++;
    }
    while (i < n && S[i] == '0') i++;
    while (i < n && '0' <= S[i] && S[i] <= '9') {
      int a = S[i] - '0';
      // 1. ans * 10 + a > INT_MAX
      // 2. -ans * 10 < INT_MIN + a
      if (sign ==  1 && (ans > M || (ans == M && a >= 7))) return INT_MAX;
      if (sign == -1 && (ans > M || (ans == M && a >= 8))) return INT_MIN;
      ans *= 10;
      ans += a;
      i++;
    }
    return sign * ans;
  }
};

// leet7
class Solution {
public:
  int reverse(int X) {
    int ans = 0;
    while (X) {
      ans *= 10;
      ans += X % 10;
      X /= 10;
      if ((X > 0 && (ans > (INT_MAX - X % 10) / 10))) {
        return 0;
      }
      // (ans * 10 + X % 10) < INT_MIN
      if (X < 0 && (ans < (INT_MIN - X % 10) / 10)) {
        return 0;
      }
    }
    return ans;
  }
};
