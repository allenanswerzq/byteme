/* created   : 2020-10-02 22:21:22
 * accepted  : 2020-10-02 22:21:22
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
    leaf.resize(N);
  }

  void insert(string word) {
    int u = 0;
    for (char c : word) {
      int t = c - 'a';
      if (!node[u][t]) {
        node[u][t] = p++;
      }
      u = node[u][t];
    }
    leaf[u] = true;
  }

  bool search(string word) {
    int u = 0;
    for (char c : word) {
      int t = c - 'a';
      if (!node[u][t]) return false;
      u = node[u][t];
    }
    return leaf[u];
  }

  bool startsWith(string prefix) {
    int u = 0;
    for (char c : prefix) {
      int t = c - 'a';
      if (!node[u][t]) return false;
      u = node[u][t];
    }
    return true;
  }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& A, vector<string>& W) {
    int n = A.size();
    int m = A[0].size();
    Trie trie;
    int mx = 0;
    for (string& w : W) {
      trie.insert(w);
      mx = max(mx, (int)w.size());
    }
    unordered_set<string> ans;
    vector<vector<bool>> use(n, vector<bool>(m));
    std::function<void(int, int, string&)> dfs = [&](int x, int y,
                                                     string& path) {
      use[x][y] = true;
      path.push_back(A[x][y]);
      if (trie.search(path)) {
        ans.insert(path);
      }
      if (trie.startsWith(path) && path.size() < mx) {
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (!(0 <= nx && nx < n)) continue;
          if (!(0 <= ny && ny < m)) continue;
          if (use[nx][ny]) continue;
          dfs(nx, ny, path);
        }
      }
      path.pop_back();
      use[x][y] = false;
    };
    // a b
    // a a
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c = A[i][j];
        if (trie.startsWith(string(1, c))) {
          string path;
          dfs(i, j, path);
          dfs
          assert(path.empty());
        }
      }
    }
    return vector<string>(ans.begin(), ans.end());
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
