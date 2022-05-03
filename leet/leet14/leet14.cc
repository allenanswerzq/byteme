/* created   : 2022-05-01 17:14:55
 * accepted  : 2022-05-01 17:14:56
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

struct Trie {
  vector<array<int, 26>> node;
  vector<int> cnt;
  int p = 1;
  const int N = 1e4;

  Trie() {
    node.resize(N);
    cnt.resize(N);
  }

  void add(const string &S) {
    int u = 0;
    for (char ch : S) {
      int c = ch - 'a';
      if (!node[u][c]) {
        node[u][c] = p++;
      }
      u = node[u][c];
      cnt[u]++;
    }
  }
};

class Solution {
public:
  string longestCommonPrefix(vector<string> & S) {
    int n = S.size();
    Trie trie;
    for (auto &s : S) {
      trie.add(s);
    }
    int u = 0;
    string ans = "";
    for (int i = 0; i <= S[0].size(); i++) {
      if (i == S[0].size())
        return S[0];
      int c = S[0][i] - 'a';
      int t = trie.node[u][c];
      // cout << S[0][i] << " " << t << " " << trie.cnt[t] << endl;
      if (t && trie.cnt[t] == n) {
        u = t;
      } else {
        ans = S[0].substr(0, i);
        break;
      }
    }
    return ans;
  }
};
