/* created   : 2021-01-13 22:46:27
 * accepted  : 2021-01-14 16:17:19
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
    trace(s, bs);
    for (int i = bs.size() - 1; i >= 0; i--) {
      int v = bs[i];
      // trace(i, v);
      assert(u < N);
      if (!node[u][v]) {
        node[u][v] = p++;
      }
      u = node[u][v];
      count[u]++;
    }
    leaf[u]++;
  }

  int find(int s, int K) {
    int u = 0;
    auto bs = bitset<30>(s);
    auto bk = bitset<30>(K);
    int ans = 0;
    for (int i = bs.size() - 1; i >= 0; i--) {
      int c = bs[i], d = bk[i];
      if (d) {
        // 1): If the current bit of K is 1, `s` go to the same side,
        // will have 0 which definitly less than k
        // assert(node[u][c]);
        if (node[u][c]) {
          ans += count[node[u][c]];
        }
        // 2): go to the left side
        if (node[u][!c]) {
          u = node[u][!c];
        }
        else {
          // assert(false);
          return ans;
        }
      }
      else {
        if (node[u][c]) {
          u = node[u][c];
        }
        else {
          // assert(false);
          return ans;
        }
    }
    return ans;
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
    trace(i, x);
    s ^= x;
    ans += trie.find(s, K);
    trace(i, ans);
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
