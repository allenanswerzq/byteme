/* created   : 2020-10-02 14:33:42
 * accepted  : 2020-10-02 14:33:42
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Description
// Given an input character array, reverse the array word by word. A word is defined as a sequence of non-space characters.

// The input character array does not contain leading or trailing spaces and the words are always separated by a single space.

// Have you met this question in a real interview?
// Example
// Example1

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example2

// Input: "a b c"
// Output: "c b a"
// Challenge
// Could you do it in-place without allocating extra space?

class Solution {
public:
  string reverseWords(string& S) {
    reverse(S.begin(), S.end());
    int n = S.size();
    for (int lo = 0, i = 0; i <= n; i++) {
      if (i == n || S[i] == ' ') {
        reverse(S.begin() + lo, S.begin() + i);
        lo = i + 1;
      }
    }
    return S;
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
