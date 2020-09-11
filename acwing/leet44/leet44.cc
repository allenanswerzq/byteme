/* created   : 2020-09-11 10:17:39
 * accepted  : 2020-09-11 16:15:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 1234;
int save[N][N];

class Solution {
public:
  bool dfs(const string& text, const string& pat, int t, int p) {
    // trace(text.substr(t), pat.substr(p), t, p);
    int& ans = save[t][p];
    if (ans != -1) {
      return ans;
    }
    if (p == pat.size()) {
      return ans = (t == text.size());
    }
    if (t == text.size()) {
      for (int i = p; i < pat.size(); i++) {
        if (pat[i] != '*') return ans = false;
      }
      return true;
    }
    if (pat[p] == '*') {
      while (p < pat.size() && pat[p] == '*') {
        p++;
      }
      for (int i = t; i <= text.size(); i++) {
        if (dfs(text, pat, i, p)) {
          return ans = true;
        }
      }
    }
    else if (pat[p] == '?') {
      return ans = dfs(text, pat, t + 1, p + 1);
    }
    else {
      return ans = (text[t] == pat[p] && dfs(text, pat, t + 1, p + 1));
    }
    return ans = false;
  }

  bool isMatchDfs(string s, string p) {
    memset(save, 0xff, sizeof(save));
    return dfs(s, p, 0, 0);
  }

  bool isMatch(string text, string pat) {
    int t = 0;
    int p = 0;
    int it = -1;
    int ip = 0;
    while (t < text.size()) {
      // trace(t, p, it, ip);
      if (p < pat.size() && (pat[p] == '?' || pat[p] == text[t])) {
        p++, t++;
      }
      else if (p < pat.size() && pat[p] == '*') {
        it = t;
        ip = p;
        p++;
      }
      else if (it >= 0) {
        t = ++it;
        p = ip + 1;
      }
      else {
        return false;
      }
    }
    while (p < pat.size() && pat[p] == '*') {
      p++;
    }
    return p == pat.size();
  }
};

bool test(string s, string p) {
  Solution sol;
  return sol.isMatch(s, p);
}

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)

void solve() {
  EXPECT_FALSE(test("aa", "a"));
  EXPECT_TRUE(test("aa", "*"));
  EXPECT_FALSE(test("cb", "?a"));
  EXPECT_TRUE(test("adceb", "*a*b"));
  EXPECT_FALSE(test("acdcb", "a*c?b"));
  EXPECT_TRUE(test("a", "a*"));
  EXPECT_FALSE(test("acdcb", "a*c?b"));
  EXPECT_FALSE(test("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
  EXPECT_FALSE(test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
"*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*"));
  EXPECT_TRUE(test("abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb",
"***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**"));
  EXPECT_FALSE(test("cabbbbaa", "**cbb"));

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
