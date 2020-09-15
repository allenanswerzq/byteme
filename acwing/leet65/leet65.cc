/* created   : 2020-09-14 22:49:46
 * accepted  : 2020-09-15 19:51:23
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  bool isNumber(string A) {
    while (A.size() && A.back() == ' ') {
      A.pop_back();
    }
    int i = 0;
    int n = A.size();
    while (i < n && A[i] == ' ') i++;
    if (i == n) return false;
    if (A[i] == '-' || A[i] == '+') {
      i++;
    }
    if (i == n) return false;
    int k = 0;
    while (i < n && isdigit(A[i])) {
      i++, k++;
    }
    if (i == n) return true;
    if (A[i] == '.') {
      i++;
      int g = 0;
      while (i < n && isdigit(A[i])) {
        i++, g++;
      }
      if (i == n) {
        if (k == 0 && g == 0) return false;
        return true;
      }
      else if (i < n && (A[i] == 'e' || A[i] == 'E')) {
        i++;
        if ((k == 0 && g == 0) || i == n) return false;
        if (A[i] == '-' || A[i]  == '+') {
          i++;
        }
        // 123.e(+/-)1234
        int c = 0;
        while (i < n && isdigit(A[i])) {
          i++, c++;
        }
        return c > 0 && i == n;
      }
      else {
        return false;
      }
    }
    else if (A[i] == 'e') {
      i++;
      if (k == 0 || i == n) return false;
      if (A[i] == '-' || A[i]  == '+') {
        i++;
      }
      // 123.e(+/-)1234
      int c = 0;
      while (i < n && isdigit(A[i])) {
        i++, c++;
      }
      return c > 0 && i == n;
    }
    else {
      return false;
    }
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

bool test(string a) {
  Solution sol;
  return sol.isNumber(a);
}

void solve() {
  EXPECT_FALSE(test("6+1"));
  EXPECT_TRUE(test("-1."));
  EXPECT_FALSE(test(".e1"));
  EXPECT_FALSE(test("."));
  EXPECT_FALSE(test(".  "));
  EXPECT_TRUE(test("0.e23"));
  EXPECT_TRUE(test("0.e-23"));
  EXPECT_TRUE(test("0.e+23"));
  EXPECT_TRUE(test("0."));
  EXPECT_TRUE(test("0.   "));
  EXPECT_TRUE(test("   .0   "));
  EXPECT_FALSE(test("  "));
  EXPECT_TRUE(test("0"));
  EXPECT_TRUE(test(" 0.1 "));
  EXPECT_FALSE(test("abc"));
  EXPECT_FALSE(test("1 a"));
  EXPECT_TRUE(test("2e10"));
  EXPECT_TRUE(test(" -90e3   "));
  EXPECT_FALSE(test(" 1e"));
  EXPECT_FALSE(test("e3"));
  EXPECT_TRUE(test(" 6e-1"));
  EXPECT_FALSE(test(" 99e2.5 "));
  EXPECT_TRUE(test("53.5e93"));
  EXPECT_FALSE(test(" --6 "));
  EXPECT_FALSE(test("-+3"));
  EXPECT_FALSE(test("95a54e53"));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
