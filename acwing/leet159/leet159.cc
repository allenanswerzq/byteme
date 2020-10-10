/* created   : 2020-09-30 20:40:26
 * accepted  : 2020-09-30 20:57:37
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// Description
// Given a string S, find the length of the longest substring T that contains at
// most k distinct characters.

// Have you met this question in a real interview?
// Example
// Example 1:

// Input: S = "eceba" and k = 3
// Output: 4
// Explanation: T = "eceb"
// Example 2:

// Input: S = "WORLD" and k = 4
// Output: 4
// Explanation: T = "WORL" or "ORLD"
// Challenge
// O(n) time

class Solution {
 public:
  /**
   * @param s: A string
   * @param k: An integer
   * @return: An integer
   */
  int lengthOfLongestSubstringKDistinctNaive(string& S, int K) {
    if (K == 0) return 0;
    int n = S.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        vector<int> cnt(256);
        for (int k = i; k <= j; k++) {
          cnt[S[k]]++;
        }
        int t = 0;
        for (int k = 0; k < 256; k++) {
          t += (cnt[k] > 0);
        }
        if (t <= K) {
          ans = max(ans, j - i + 1);
        }
        // if (ans == 27) {
        //   trace(i, j, t, ans);
        // }
      }
    }
    return ans;
  }

  int lengthOfLongestSubstringKDistinct(string &S, int K) {
    if (K == 0) return 0;
    vector<int> cnt(256);
    int c = 0;
    int ans = 0;
    for (int hi = 0, lo = 0; lo < S.size(); lo++) {
      if (lo > hi) hi = lo;
      while (hi < S.size() && cnt[c] && c + 1 <= K) {
        cnt[S[hi]]++;
        if (cnt[S[hi]] == 1) {
          c++;
        }
        hi++;
      }
      // trace(lo, hi, c);
      ans = max(ans, hi - lo);
      if (cnt[S[lo]] == 1) {
        c--;
      }
      cnt[S[lo]]--;
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void test(string S, int K) {
  Solution sol;
  int a = sol.lengthOfLongestSubstringKDistinct(S, K);
  int b = sol.lengthOfLongestSubstringKDistinctNaive(S, K);
  trace(a, b);
  EXPECT(a, b);
}

void solve() {
  test("abcefefefef", 5);
  test("WROLD", 4);
  test("eqgkcwGFvjjmxutystqdfhuMblWbylgjxsxgnoh", 16);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
