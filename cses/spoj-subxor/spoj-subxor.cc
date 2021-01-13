/* created   : 2021-01-13 22:46:27
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

// link: https://www.spoj.com/problems/SUBXOR/

template <int N>
struct Trie {
  vector<array<int, 2>> node;
  vector<int> count;
  vector<int> leaf;
  int p = 1;  // 0 is reserved for trie root node.

  Trie() {
    node.resize(N);
    leaf.resize(N);
    count.resize(N);
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
        count[u]++;
        node[u][v] = p++;
      }
      u = node[u][v];
    }
    leaf[u]++;
  }

  int find(int s, int K) {
    int u = 0;
    auto bs = bitset<30>(s);
    auto bk = bitset<30>(K);
    for (int i = bs.size() - 1; i >= 0; i--) {
      if (bs[i] < bk[i]) {
        return count[u];
      }
      else if (bs[i] == bk[i]) {
      }
      else if (node[u][!c]) {
        u = node[u][!c];
      }
      else {
        assert(false);
      }
    }
    return 0;
  }
};

void solve() {
  int N, K; cin >> N >> K;
  Trie<(int)1e6> trie;
  int s = 0;
  ll ans = 0;
  trie.add(0);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    s ^= x;
    ans += trie.find(s, K);
    trie.add(s);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
