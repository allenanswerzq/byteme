/* created   : 2020-10-13 23:03:04
 * accepted  : 2020-10-13 23:03:05
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Description
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

// Have you met this question in a real interview?
// Example
// Example 1:

// Input：["practice", "makes", "perfect", "coding", "makes"],"coding","practice"
// Output：3
// Explanation：index("coding") - index("practice") = 3
// Example 2:

// Input：["practice", "makes", "perfect", "coding", "makes"],"makes","coding"
// Output：1
// Explanation：index("makes") - index("coding") = 1

class Solution {
public:
  /**
   * @param words: a list of words
   * @param word1: a string
   * @param word2: a string
   * @return: the shortest distance between word1 and word2 in the list
   */
  int shortestDistance(vector<string> &W, string &w1, string &w2) {
    int ans = W.size(), p1 = -1, p2 = -1;
    for (int i = 0; i < W.size(); i++) {
      if (W[i] == w1) {
        p1 = i;
      }
      if (W[i] == w2) {
        p2 = i;
      }
      if (p1 != -1 && p2 != -1) {
        ans = min(ans, abs(p1 - p2));
      }
    }
    assert(ans != W.size());
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
