/* created   : 2020-10-15 22:17:28
 * accepted  : 2020-10-15 22:17:28
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Description
// A mirror number is a number that looks the same when rotated 180 degrees (looked at upside down).For example, the numbers "69", "88", and "818" are all mirror numbers.

// Write a function to determine if a number is mirror. The number is represented as a string.

// Have you met this question in a real interview?
// Example
// Example 1:

// Input : "69"
// Output : true
// Example 2:

// Input : "68"
// Output : false

class Solution {
public:
  /**
   * @param num: a string
   * @return: true if a number is strobogrammatic or false
   */
  bool isStrobogrammatic(string& S) {
    vector<char> s = {'6', '0', '8', '1'};
    vector<char> t = {'9', '0', '8', '1'};
    int lo = 0, hi = S.size() - 1;
    while (lo <= hi) {
      bool ok = false;
      for (int k = 0; k < s.size(); k++) {
        if ((S[lo] == s[k] && S[hi] == t[k]) ||
            (S[lo] == t[k] && S[hi] == s[k])) {
          ok = true;
          break;
        }
      }
      if (!ok) return false;
      lo++, hi--;
    }
    return true;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
