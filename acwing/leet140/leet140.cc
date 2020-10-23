/* created   : 2020-09-26 17:15:52
 * accepted  : 2020-09-26 21:06:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  unordered_map<string, vector<vector<string>>> mp;
  vector<vector<string>> dfs(const string& S, vector<string>& W) {
    if (S.empty()) return {{}};
    if (mp.count(S)) return mp[S];
    // trace(S);
    vector<vector<string>> ans;
    for (const string& w : W) {
      int m = w.size();
      if (m <= S.size() && S.substr(0, m) == w) {
        auto tmp = dfs(S.substr(m), W);
        for (auto& t : tmp) {
          t.push_back(w);
          ans.push_back(t);
        }
      }
    }
    return mp[S] = ans;
  }

  vector<string> wordBreak(string S, vector<string>& W) {
    return ret;
  }
};

void test(string S, vector<string> W) {
  Solution sol;
  auto t = sol.wordBreak(S, W);
  trace(t);
}

void solve() {
  test("catsanddog", {"cat", "cats", "and", "sand", "dog"});
  test("pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"});
  test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
