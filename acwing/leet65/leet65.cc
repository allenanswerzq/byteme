/* created   : 2020-09-14 22:49:46
 * accepted  : 2020-09-14 22:54:31
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  struct Config {
    bool allow_prefix;
    bool allow_neg;
    bool allow_pos;
    bool allow_suffix;
  };

  // ___-2345___
  bool searchNumber(const string& A, int i, Config cfg, int* ret) {
    int n = A.size();
    *ret = n;
    if (i == n) {
      return false
    }
    if (cfg.allow_prefix) {
      while (i < n && A[i] == ' ') i++;
    }
    if (cfg.allow_pos && cfg.allow_neg) {
      if (i < n && A[i] != '-' && A[i] != '+') {
        return false;
      }
      i++;
    }
    else if (cfg.allow_neg) {
      if (i < n && A[i] != '-') {
        return false;
      }
      i++;
    }
    if (i == n || !isdigit(A[i])) {
      return false;
    }
    while (i < n && isdigit(A[i])) {
      i++;
    }
    if (cfg.allow_suffix) {
      while (i < n && A[i] == ' ') {
        i++;
      }
      *ret = i;
      return true;
    }
    else {
      *ret = i;
      return i == n || (A[i] == ' ');
    }
  }

  bool dfs(const string& A, int i) {
    int n = A.size();
    while (i < n && A[i] == ' ') i++;
    if (i == n) {
      return false;
    }
    else if (A[i] == '-' || A[i] == '+') {
      i++;
      return isdigit(A[i]) && dfs(A, i + 1);
    }
    else if (isdigit(A[i])) {
      return dfs(A, i + 1);
    }
    else if (A[i] == '.') {
      Config cfg;
      cfg.allow_suffix = true;
      int k = 0;
      if (!searchNumber(A, i + 1, cfg, &k)) {
        return false;
      }
      return k == n;
    }
    else if (A[i] == 'e') {

    }
    else {
      return false;
    }
  }

  bool isNumber(string A) {
    return dfs(A, 0);
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
