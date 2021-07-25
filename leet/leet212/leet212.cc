/* created   : 2020-10-02 22:21:22
 * accepted  : 2020-10-18 23:26:21
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Trie {
 public:
  vector<array<int, 26>> node;
  vector<int> leaf;
  int p = 1;

  Trie() {
    int N = 100000;
    node.resize(N);
    leaf.resize(N, -1);
  }

  void insert(int idx, const string& word) {
    int u = 0;
    for (char c : word) {
      int t = c - 'a';
      assert(t < 26);
      if (!node[u][t]) {
        node[u][t] = p++;
      }
      u = node[u][t];
    }
    leaf[u] = idx;
  }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& A, vector<string>& W) {int n = A.size();
    int m = A[0].size();
    Trie trie;
    for (int i = 0; i < W.size(); i++) {
      trie.insert(i, W[i]);
    }
    vector<string> ans;
    std::function<void(int, int, int)> dfs = [&](int x, int y, int u) {
      if (A[x][y] == '.') return;
      char c = A[x][y];
      u = trie.node[u][c - 'a'];
      if (trie.leaf[u] >= 0) {
        ans.push_back(W[trie.leaf[u]]);
        trie.leaf[u] = -1;
      }
      if (!u) return;
      A[x][y] = '.';
      if (x) dfs(x - 1, y, u);
      if (y) dfs(x, y - 1, u);
      if (x + 1 < n) dfs(x + 1, y, u);
      if (y + 1 < m) dfs(x, y + 1, u);
      A[x][y] = c;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c = A[i][j];
        if (trie.node[0][c - 'a']) {
          dfs(i, j, 0);
        }
      }
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void test(vector<vector<char>> A, vector<string> W) {
  Solution sol;
  trace(A);
  auto ans = sol.findWords(A, W);
  trace(ans);
}

void solve() {
  test(vector<vector<char>>({{'a'}}), vector<string>({"a"}));

  test(vector<vector<char>>({{'a', 'b'}, {'a', 'b'}}),
        vector<string>({"a", "b"}));

  test(vector<vector<char>>({{'o', 'a', 'a', 'n'},
                             {'e', 't', 'a', 'e'},
                             {'i', 'h', 'k', 'r'},
                             {'i', 'f', 'l', 'v'}}),
       vector<string>({"oath", "pea", "eat", "rain"}));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
