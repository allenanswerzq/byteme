/* created   : 2020-09-20 10:14:15
 * accepted  : 2020-09-20 10:34:22
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  vector<string> restoreIpAddresses(string S) {
    if (S.empty()) return {};
    if (S.size() > 12) return {};
    int n = S.size();
    auto check = [](string s) {
      if (s.empty()) return false;
      if (s.size() > 3) return false;
      if (stoi(s) > 255) return false;
      if (stoi(s) == 0 && s.size() > 1) return false;
      if (stoi(s) > 0 && s[0] == '0') return false;
      return true;
    };
    // [(0...i) (i + 1...j) (j+1...k) (k+1...n-1)]
    vector<string> ans;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          string a = S.substr(0, i + 1);
          string b = S.substr(i + 1, j - i);
          string c = S.substr(j + 1, k - j);
          string d = S.substr(k + 1);
          if (check(a) && check(b) && check(c) && check(d)) {
            string t;
            t.append(a);
            t.append(".");
            t.append(b);
            t.append(".");
            t.append(c);
            t.append(".");
            t.append(d);
            ans.push_back(t);
          }
        }
      }
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void test(const string& s) {
  Solution sol;
  trace(sol.restoreIpAddresses(s));
}

void solve() {
  test("255255255255");
  test("25525511135");
  test("0000");
  test("1111");
  test("010010");
  test("101023");
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
