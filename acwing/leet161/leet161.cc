/* created   : 2020-09-30 21:00:04
 * accepted  : 2020-09-30 21:30:58
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Description
// Given two strings S and T, determine if they are both one edit distance apart.
// One ediit distance means doing one of these operation:

// insert one character in any position of S
// delete one character in S
// change one character in S to other character
// Have you met this question in a real interview?
// Example
// Example 1:

// Input: s = "aDb", t = "adb"
// Output: true
// Example 2:

// Input: s = "ab", t = "ab"
// Output: false
// Explanation:
// s=t ,so they aren't one edit distance apart

class Solution {
public:
  /**
   * @param s: a string
   * @param t: a string
   * @return: true if they are both one edit distance apart or false
   */
  bool tryInsertOrDelete(const string& S, const string& T) {
    int n = S.size();
    int m = T.size();
    assert(n < m);
    int i = 0;
    int j = 0;
    bool ok = false;
    while (j < m) {
      if (i < n && S[i] == T[j]) {
        i++, j++;
      }
      else if (!ok) {
        ok = true;
        j++;
      }
      else if (ok) {
        return false;
      }
    }
    return (i == n && j == m && ok);
  }

  bool tryChange(const string& S, const string& T) {
    int n = S.size();
    int m = T.size();
    if (m != n) {
      return false;
    }
    int i = 0;
    int j = 0;
    bool ok = false;
    while (i < n && j < m) {
      if (S[i] == T[j]) {
        i++, j++;
      }
      else if (!ok) {
        ok = true;
        i++, j++;
      }
      else if (ok) {
        return false;
      }
    }
    return (i == n && j == m && ok);
  }

  bool isOneEditDistance(string& S, string& T) {
    bool ans = false;
    int n = S.size(), m = T.size();
    if (abs(n - m) > 1) {
      return false;
    }
    if (n < m) {
      ans |= tryInsertOrDelete(S, T);
    }
    else if (n > m) {
      ans |= tryInsertOrDelete(T, S);
    }
    else {
      ans |= tryChange(S, T);
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

bool test(string S, string T) {
  Solution sol;
  return sol.isOneEditDistance(S, T);
}

void solve() {
  EXPECT_TRUE(test("ab", "a"));
  EXPECT_TRUE(test("a", "ab"));
  EXPECT_TRUE(test("ab", "adb"));
  EXPECT_TRUE(test("aDb", "adb"));
  EXPECT_FALSE(test("ab", "ab"));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
