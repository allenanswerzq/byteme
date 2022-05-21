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

    Trie () {
      node.resize(N);
      leaf.resize(N);
    }

    void add(const string& ss) {
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

  void trace(vector<vector<int>>& v) {
    for (auto & t : v) {
      int m = t.size();
      cout << "[";
      for (int i = 0; i < m; i++) {
        cout << t[i] << " ";
      }
      cout << "]\n";
    }
  }

  vector<string> wordBreak(string S, vector<string>& W) {
    Trie tr;
    for (auto & w : W) {
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
    vector<vector<int>> ans;
    std::function<void(int,vector<int>&)> dfs =[&](int u, vector<int>&path) {
      if (u == n) {
        ans.push_back(path);
        return;
      }
      for (int v : g[u]) {
        path.push_back(v);
        dfs(v, path);
        path.pop_back();
      }
    };
    vector<int> path;
    dfs(0, path);
    vector<string> res;
    for (auto & v : ans) {
      string cur = S;
      for (int i = 0; i + 1 < v.size(); i++) {
        cur.insert(v[i] + i, 1, ' ');
      }
      res.push_back(cur);
    }
    return res;
  }
};
