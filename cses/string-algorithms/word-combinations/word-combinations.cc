/* created   : 2020-12-28 21:59:00
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <int N>
struct Trie {
  vector<array<int, 26>> node;
  vector<int> leaf;
  int p = 1;  // 0 is reserved for trie root node.

  Trie() {
    node.resize(N);
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
    if (ret) {
      *ret = leaf[u];
    }
    return leaf[u] > 0;
  }
};

const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

void solve() {
  string S; cin >> S;
  int K; cin >> K;
  const int Z = 1e6 + 7;
  Trie<Z> trie;
  while (K--) {
    string t; cin >> t;
    trie.add(t);
  }
  int n = S.size();
  vector<int> f(n + 1);
  f[0] = 1;
  for (int i = 0; i < n; i++) {
    int u = 0;
    for (int j = i; j < n; j++) {
      u = trie.node[u][S[j] - 'a'];
      if (!u) break;
      // [i...j]
      if (trie.leaf[u]) {
        add(f[j + 1], f[i]);
      }
    }
  }
  cout << f[n] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
