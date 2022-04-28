/* created   : 2020-09-20 17:10:30
 * accepted  : 2020-09-20 18:03:38
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// The test cases are generated so that the answer fits on a 32-bit signed integer.



// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag


// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.

class Solution {
public:
  // f[i][j] = f[i - 1][j] + f[i - 1][j - 1] (iff S[i] == T[i])
  int numDistinct(string S, string T) {
    int n = S.size();
    int m = T.size();
    vector<vector<ll>> f(n + 1, vector<ll>(m + 1));
    for (int i = 0; i <= n; i++) {
      f[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = f[i - 1][j];
        if (S[i - 1] == T[j - 1]) {
          f[i][j] += f[i - 1][j - 1];
        }
        // trace(i, j, f[i][j], S.substr(0, i), T.substr(0, j));
      }
    }
    return f[n][m];
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(const string& S, const string& T) {
  Solution sol;
  return sol.numDistinct(S, T);
}

void solve() {
  EXPECT(dbg(test("rabbbit", "rabbit")), 3);
  EXPECT(dbg(test("babgbag", "bag")), 5);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
