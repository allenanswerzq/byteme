/* created   : 2020-06-07 18:05:58
 * accepted  : 2020-07-15 08:20:38
 * https://leetcode.com/problems/regular-expression-matching/
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
    bool rec(const string& s, const string& p, int si, int pi) {
        trace(s, p, si, pi);
        int n = s.size(), m = p.size();
        if (si < n && pi == m) return false;
        if (si == n) {
            if (pi == m) return true;
            if (p[pi] == '*') {
                assert(false);
            }
            else if (p[pi] == '.') {
                int cnt = 0;
                for (int i = pi + 1; i < m; i++) {
                    if (p[i] == '*') cnt++;
                }
                // "", ".*****"
                return cnt && cnt == (m - pi - 1);
            }
            else {
                // "" "b*b*c*****d*"
                for (int i = pi; i < m; ) {
                    i++;
                    if (p[i] != '*') return false;
                    while (i < m && p[i] == '*') i++;
                }
                return true;
            }
        }
        if (p[pi] == '.') {
            if (p[pi + 1] == '*') {
                pi++;
                // .******|
                while (pi < m && p[pi] == '*') pi++;
                for (int i = si; i <= n; i++) {
                    if (rec(s, p, i, pi)) return true;
                }
            }
            else {
                if (rec(s, p, si + 1, pi + 1)) return true;
            }
        }
        else if (p[pi] == '*') {
            assert(p[pi - 1] != '.');
            // __xabcdef
            // __x*
            // Matches 0 previous char.
            if (rec(s, p, si, pi + 1)) return true;
            // Matches more previous char.
            char pre = p[pi - 1];
            for (int i = si; i < n; i++) {
                if (s[i] == pre) {
                    if (rec(s, p, i + 1, pi + 1)) return true;
                }
                else {
                  break;
                }
            }
        }
        else {
            if (pi + 1 < m && p[pi + 1] == '*') {
                if (rec(s, p, si, pi + 1)) return true;
            }
            else {
                if (s[si] == p[pi] && rec(s, p, si + 1, pi + 1)) return true;
            }
        }
        return false;
    }

    bool isMatch(string s, string p) {
        return rec(s, p, 0, 0);
    }
};

int test(const string& s, const string& p) {
  Solution sol;
  return sol.isMatch(s, p);
}

#define expect(a, b) assert(a == b)

void solve() {
  expect(test("aa", "a"), 0);
  expect(test("aa", "a*"), 1);
  expect(test("", ".*"), 1);
  expect(test("", ".*************"), 1);
  expect(test("ab", ""), 0);
  expect(test("ab", ".*"), 1);
  expect(test("aab", "c*a*b"), 1);
  expect(test("mississippi", "mis*is*p*."), 0);
  expect(test("a", "ab*"), 1);
  expect(test("a", "ab*a"), 0);
  expect(test("a", ".*.."), 0);
  expect(test("", "c*c*"), 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
