/* created   : 2020-09-17 18:59:39
 * accepted  : 2020-09-17 23:53:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  string minWindow(string S, string T) {
    vector<int> cnt(256);
    for (int i = 0; i < T.size(); i++) {
      cnt[T[i]]++;
    }
    int lo = 0;
    int n = S.size();
    array<int, 2> ans{-1, -1};
    int total = T.size();
    for (int hi = 0; lo < n; ) {
      if (lo > hi) {
        hi = lo;
      }
      while (hi < n && total > 0) {
        if (cnt[S[hi]] > 0) {
          total--;
        }
        cnt[S[hi++]]--;
      }
      // trace(lo, hi, cnt);
      // [lo...hi)
      if (total == 0) {
        if (ans[0] == -1 && ans[1] == -1) {
          ans = {lo, hi};
        }
        else if (ans[1] - ans[0] > hi - lo) {
          ans = {lo, hi};
        }
      }
      if (++cnt[S[lo++]] > 0) {
        total++;
      }
    }
    if (ans[0] == -1 && ans[1] == -1) return "";
    return S.substr(ans[0], ans[1] - ans[0]);
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

string test(string s, string t) {
  Solution sol;
  return sol.minWindow(s, t);
}

void solve() {
  EXPECT(test("bbaac", "aba"), "baa");
  EXPECT(test("aaaaaaaaaaaabbbbbcdd", "abcdd"), "abbbbbcdd");
  EXPECT(dbg(test("aa", "aa")), "aa");
  EXPECT(test("", "ABC"), "");
  EXPECT(dbg(test("ADOBECODEBANC", "ABC")), "BANC");
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
