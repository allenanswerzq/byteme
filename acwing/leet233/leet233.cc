/* created   : 2020-10-04 19:12:58
 * accepted  : 2020-10-04 20:36:36
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  int countDigitOne(int N) {
    // 1: 9:   1   00 01 02 .. 09
    // 2: 99:  19  10 11 12 13 19 / 21 31... 91
    // 3: 999:     1)00 1)01 2)01  ... 9)01
    //             100 ... 199 20 + (100)
    // 199
    if (N <= 0) return 0;
    string s = to_string(N);
    int n = s.size();
    // 32345
    // 2xxxx
    // 12345
    // 10001
    // 10000
    // 09999
    ll hi = s[0] - '0';
    ll p = (int) pow(10, n - 1);
    ll r = N - hi * p;
    if (hi == 1) {
      return countDigitOne(p - 1) + countDigitOne(r) + r + 1; /*10000*/
    }
    else {
      // 100..00 199...99
      return hi * countDigitOne(p - 1) + p + countDigitOne(r);
    }
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(int N) {
  Solution sol;
  return dbg(sol.countDigitOne(N));
}

void solve() {
  EXPECT(test(9), 1);
  EXPECT(test(99), 20);
  EXPECT(test(100), 21);
  EXPECT(test(199), 140);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
