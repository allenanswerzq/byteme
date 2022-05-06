/* created   : 2020-09-26 17:15:52
 * accepted  : 2020-09-26 21:06:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

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

  void trace(vector<vector<int>> &v) {
    for (auto &t : v) {
      int m = t.size();
      cout << "[";
      for (int i = 0; i < m; i++) {
        if (i > 0)
          cout << " ";
        cout << t[i];
      }
      cout << "]\n";
    }
  }

  vector<string> wordBreak(string S, vector<string> &W) {
    Trie tr;
    for (auto &w : W) {
      tr.add(w);
    }
    int n = S.size();
    vector<int> f(n + 1);
    f[0] = 1;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++) {
      int u = 0;
      int c = S[i] - 'a';
      int j = i;
      while (j < n && tr.node[u][c]) {
        u = tr.node[u][c];
        if (tr.leaf[u]) {
          f[j + 1] |= f[i];
          g[i].push_back(j + 1);
        }
        c = S[++j] - 'a';
      }
    }
    // trace(g);
    vector<vector<int>> ans;
    std::function<void(int, vector<int> &)> dfs = [&](int u, vector<int> &path) {
      path.push_back(u);
      if (u == n) {
        ans.push_back(path);
        path.pop_back();
        return;
      }
      for (int v : g[u]) {
        dfs(v, path);
      }
      path.pop_back();
    };
    vector<int> path;
    dfs(0, path);
    // trace(ans);
    vector<string> res;
    for (auto &v : ans) {
      string cur = S;
      for (int i = 1; i + 1 < v.size(); i++) {
        cur.insert(v[i] + i - 1, 1, ' ');
      }
      res.push_back(cur);
    }
    return res;
  }
};

void solve() {
  test("catsanddog", {"cat", "cats", "and", "sand", "dog"});
  test("pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"});
  test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
       "aaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
       "aaaaaaaaa",
       {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa",
        "aaaaaaaaa", "aaaaaaaaaa"});
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
