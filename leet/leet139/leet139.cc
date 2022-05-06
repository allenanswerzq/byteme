/* created   : 2020-09-26 16:36:13
 * accepted  : 2020-09-26 17:12:24
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  bool wordBreak(string S, vector<string> &W) { return wordBreakDP(S, W); }

  bool wordBreakDP(string S, vector<string> &W) {
    unordered_set<string> WD;
    for (string &w : W) {
      WD.insert(w);
    }
    int n = S.size();
    vector<int> f(n + 1);
    f[n] = 1;
    // f[i] |= f[i + len]
    for (int i = n - 1; i >= 0; i--) {
      for (int len = 1; i + len <= n; len++) {
        if (WD.count(S.substr(i, len))) {
          f[i] |= f[i + len];
        }
      }
    }
    return f[0];
  }
};

class Solution {
public:
  struct Trie {
    vector<array<int, 26>> node;
    vector<int> leaf;
    int p = 1;
    const int N = 1e4;

    Trie() {
      node.resize(N);
      leaf.resize(N);
    }

    void add(const string &ss) {
      int u = 0;
      for (auto ch : ss) {
        int c = ch - 'a';
        if (!node[u][c]) {
          node[u][c] = p++;
        }
        u = node[u][c];
      }
      leaf[u]++;
    }
  };

  bool wordBreak(string S, vector<string> &W) {
    // f[i] = f[j] & (s[j...i] in W)
    Trie tr;
    for (auto &w : W) {
      tr.add(w);
    }
    int n = S.size();
    vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
      int u = 0;
      int c = S[i] - 'a';
      int j = i;
      while (j < n && tr.node[u][c]) {
        u = tr.node[u][c];
        if (tr.leaf[u]) {
          f[j + 1] |= f[i];
        }
        c = S[++j] - 'a';
      }
    }
    return f[n];
  }
};

bool test(string S, vector<string> W) {
  Solution sol;
  return sol.wordBreakDP(S, W);
}

void solve() {
  EXPECT_TRUE(test("leetcode", {"leet", "code"}));
  EXPECT_TRUE(test("applepenapple", {"apple", "pen"}));
  EXPECT_FALSE(test("catsandog", {"cats", "dog", "sand", "and", "cat"}));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
