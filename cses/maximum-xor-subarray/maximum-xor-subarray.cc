/* created   : 2021-01-12 22:41:04
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <int N>
struct Trie {
  vector<array<int, 2>> node;
  vector<int> leaf;
  int p = 1;  // 0 is reserved for trie root node.

  Trie() {
    node.resize(N);
    leaf.resize(N);
  }

  void add(int s) {
    int u = 0;
    auto bs = bitset<30>(s);
    trace(bs);
    for (int i = bs.size() - 1; i >= 0; i--) {
      int v = bs[i];
      // trace(i, v);
      assert(u < N);
      if (!node[u][v]) {
        node[u][v] = p++;
      }
      u = node[u][v];
    }
    leaf[u]++;
  }

  int find(int s) {
    int u = 0;
    auto bs = bitset<30>(s);
    int ans = 0;
    for (int i = bs.size() - 1; i >= 0; i--) {
      int c = bs[i];
      if (node[u][!c]) {
        ans |= (1 << i);
        u = node[u][!c];
      }
      else if (node[u][c]) {
        u = node[u][c];
      }
      else {
        assert(false);
      }
    }
    return ans;
  }
};

void solve() {
  int N; cin >> N;
  Trie<10000000> trie;
  int s = 0;
  int ans = 0;
  // fix y position: max{f(x, y)} = max{f(1, x-1) ^ f(1, y)}
  trie.add(0);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    s ^= x;
    ans = max(ans, trie.find(s));
    trie.add(s);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
