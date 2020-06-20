/* created   : 2020-06-20 15:29:48
 * accepted  : 2020-06-20 16:14:24
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

template <int N>
struct Trie {
  vector<array<int, 10>> node;
  vector<int> leaf;
  int p = 1;

  Trie() {
    node.resize(N);
    leaf.resize(N);
  }

  int get(char ch) { return ch - '0'; }

  bool add(const string& s) {
    int u = 0;
    bool is_prefix = false;
    bool create_new = false;
    for (auto ch : s) {
      int v = get(ch);
      if (!node[u][v]) {
        node[u][v] = p++;
        create_new = true;
      }
      u = node[u][v];
      is_prefix |= leaf[u];
    }
    leaf[u]++;
    return is_prefix || !create_new;
  }
};

void solve() {
  int n; cin >> n;
  Trie<(int)1e5 + 7> trie;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    if (trie.add(x)) {
      ok = false;
    }
  }
  cout << (ok ? "YES\n" : "NO\n");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
