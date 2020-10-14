/* created   : 2020-10-14 22:39:57
 * accepted  : 2020-10-14 22:39:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

// word1 and word2 may be the same and they represent two individual words in the list.

// For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = “makes”, word2 = “coding”, return 1.
// Given word1 = "makes", word2 = "makes", return 3.

class Solution {
 public:
  int shortestWordDistance(vector<string>& W, string w1, string w2) {
    int n = W.size(), p = -n, q = -n, ans = n;
    for (int i = 0; i < n; i++) {
      if (W[i] == w1) {
        ans = min(ans, (w1 == w2) ? i - p : i - q);
        p = i;
      }
      else if (W[i] == w2) {
        q = i;
        ans = min(ans, q - p);
      }
    }
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
