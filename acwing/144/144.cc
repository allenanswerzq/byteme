/* created   : 2020-06-08 04:49:52
 * accepted  : 2020-06-08 05:35:39
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

template <int N>
struct Trie {
  vector<vector<int>> node;
  vector<int> leaf;
  int p = 1;

  Trie() {
    node.resize(N, vector<int>(26));
    leaf.resize(N);
  }

  int get(char ch) { return ch - 'a'; }

  void add(const string& s) {
    int u = 0;
    for (auto ch : s) {
      int v = get(ch);
      if (!node[u][v]) {
        node[u][v] = p++;
      }
      u = node[u][v];
    }
    leaf[u]++;
  }

  bool find(const string& s, int* ret = nullptr) {
    int u = 0;
    for (auto ch : s) {
      int v = get(ch);
      if (!node[u][v]) {
        if (ret) *ret = 0;
        return false;
      }
      u = node[u][v];
    }
    *ret = leaf[u];
    return leaf[u] > 0;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  const int N = 1e5 + 7;
  Trie<N> trie;
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    trie.add(x);
  }
  for (int i = 0; i < m; i++) {
    string x; cin >> x;
    int cur = 0;
    for (int j = 1; j <= (int) x.size(); j++) {
      int cnt = 0;
      if (trie.find(x.substr(0, j), &cnt)) {
        cur += cnt;
      }
    }
    cout << cur << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
