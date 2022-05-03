/* created   : 2022-05-02 20:39:29
 * accepted  : 2022-05-02 20:39:30
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

struct Trie {
  vector<array<int, 26>> node;
  vector<int> leaf;
  int p = 1;
  const int N = 1e4;

  Trie() {
    node.resize(N);
    leaf.resize(N);
  }

  int add(const string &S) {
    int u = 0;
    for (char ch : S) {
      int c = ch - 'a';
      if (!node[u][c]) {
        node[u][c] = p++;
      }
      u = node[u][c];
    }
    leaf[u]++;
    return u;
  }
};

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &W) {
    int len = 0;
    Trie tr;
    map<int, int> have;
    for (auto &w : W) {
      len += w.size();
      have[tr.add(w)]++;
    }
    // aaa|aaa|
    int l = W[0].size();
    map<int, int> mp;
    auto check = [&](int p) {
      // p, p + len - 1
      mp.clear();
      for (int i = p; i < p + len; i += l) {
        int u = 0;
        bool ok = true;
        for (int j = i; j < i + l; j++) {
          int c = S[j] - 'a';
          if (tr.node[u][c]) {
            u = tr.node[u][c];
          }
          else {
            ok = false;
            break;
          }
        }
        if (!ok || !tr.leaf[u])
          return false;
        mp[u]++;
      }
      return mp == have;
    };
    vector<int> ans;
    for (int i = 0; i < l; i++) {
      for (int j = i; j + len <= S.size(); j += l) {
        // cout << "check " << j << endl;
        if (check(j)) {
          ans.push_back(j);
        }
      }
    }
    return ans;
  }
};
