/* created   : 2020-09-19 08:01:16
 * accepted  : 2020-09-19 10:15:08
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  bool isScramble(const string& A, const string& B) {
    if (A == B) return true;
    assert(A.size() == B.size());
    vector<int> cnt(26);
    for (char c : A) cnt[c - 'a']++;
    for (char c : B) cnt[c - 'a']--;
    for (int c : cnt) {
      if (c > 0) return false;
    }
    for (int len = 1; len < A.size(); len++) {
      if (isScramble(A.substr(0, len), B.substr(0, len)) &&
          isScramble(A.substr(len), B.substr(len))) {
        return true;
      }
      int n = B.size();
      if (isScramble(A.substr(0, len), B.substr(n - len, len)) &&
          isScramble(A.substr(len), B.substr(0, n - len))) {
        return true;
      }
    }
    return false;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

bool test(const string& A, const string& B) {
  Solution sol;
  return sol.isScramble(A, B);
}

void solve() {
  EXPECT_TRUE(test("abcdefghijklmnopq", "efghijklmnopqcadb"));
  EXPECT_TRUE(test("abc", "cba"));
  EXPECT_TRUE(test("abc", "acb"));
  EXPECT_TRUE(test("great", "rgeat"));
  EXPECT_FALSE(test("abcde", "caebd"));
  EXPECT_TRUE(test("a", "a"));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
