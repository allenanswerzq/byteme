/* created   : 2020-09-20 11:50:24
 * accepted  : 2020-09-20 12:58:15
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  bool isInterleaveDfs(string s1, string s2, string s3) {
    if (s3.empty()) return s1.empty() && s2.empty();
    for (int len = 1; len <= s3.size(); len++) {
      if (s3.substr(0, len) == s1.substr(0, len)) {
        if (isInterleave(s1.substr(len), s2, s3.substr(len))) {
          return true;
        }
      }
      if (s3.substr(0, len) == s2.substr(0, len)) {
        if (isInterleave(s1, s2.substr(len), s3.substr(len))) {
          return true;
        }
      }
    }
    return false;
  }

  // f[i][j][k]
  static const int N = 320;
  bool f[N][N][N];
  bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    memset(f, 0, sizeof(f));
    f[n1][n2][n3] = true;
    for (int k = n3; k >= 0; k--) {
      for (int i = n1; i >= 0; i--) {
        // n1 - i + n2 - j = n3 - k
        int j = n2 + n1 - i - (n3 - k);
        // assert(0 <= j && j <= n2);
        if (!(0 <= j && j <= n2)) continue;
        for (int len = 1; len <= n1 - i; len++) {
          if (f[i + len][j][k + len]) {
            f[i][j][k] |= (s1.substr(i, len) == s3.substr(k, len));
            if (f[i][j][k]) break;
          }
        }
        for (int len = 1; len <= n2 - j; len++) {
          if (f[i][j + len][k + len]) {
            f[i][j][k] |= (s2.substr(j, len) == s3.substr(k, len));
            if (f[i][j][k]) break;
          }
        }
      }
    }
    return f[0][0][0];
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

bool test(const string& a, const string& b, const string& c) {
  Solution sol;
  return sol.isInterleave(a, b, c);
}

void solve() {
  EXPECT_FALSE(test(
      "baababbabbababbaaababbbbbbbbbbbaabaabaaaabaaabbaaabaaaababaabaaabaabbbba"
      "abbaabaabbbbabbbababbaaaabab",
      "aababaaabbbababababaabbbababaababbababbbbabbbbbababbbabaaaaabaaabbabbaaa"
      "bbababbaaaababaababbbbabbbbb",
      "babbabbabbababbaaababbbbaababbaabbbbabbbbbaaabbabaababaabaaabaabbbaaaabb"
      "abbaaaaabbabbaabaaaabbbbababbbababbabaabababbababaaaaaabbababaaabbaabbbb"
      "aaaaabbbaaabbbabbbbaaabaababbaabababbbbababbaaabbbabbbab"));
  EXPECT_TRUE(test("aabcc", "dbbca", "aadbbcbcac"));
  EXPECT_FALSE(test("aabcc", "dbbca", "aadbbbaccc"));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
