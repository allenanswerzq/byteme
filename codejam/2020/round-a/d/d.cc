/* created   : 2020-03-22 13:39:17
 * accepted  : 2020-03-25 00:41:45
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#define xuyixuyi()
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

struct Trie {
  const bool kLower = false;

  int p = 1;
  vector<int> leaf;
  vector<vector<int>> node;

  Trie(int n) {
    leaf.resize(n);
    node.resize(n, vector<int>(26));
  }

  int get_pos(char ch) {
    if (kLower) {
      return ch - 'a';
    }
    else {
      return ch - 'A';
    }
  }

  void add(const string& s) {
    int u = 0;
    for (auto& ch : s) {
      if (!node[u][get_pos(ch)]) {
        node[u][get_pos(ch)] = p++;
      }
      u = node[u][get_pos(ch)];
    }
    leaf[u]++;
  }

  bool search(const string& s) {
    int u = 0;
    for (auto& ch : s) {
      if (!node[u][get_pos(ch)]) {
        return false;
      }
      u = node[u][get_pos(ch)];
    }
    return leaf[u] > 0;
  }

  friend debugstream& operator<<(debugstream& os, Trie& t) {
#ifdef LOCAL
    return os << t.node << "\n" << t.leaf;
#else
    (void)t;
    return os;
#endif
  }
};

int n, k;
ll ans = 0;

ll dfs(Trie& trie, int u, int d) {
  // trace(u);
  ll cur = trie.leaf[u];
  for (int i = 0; i < 26; i++) {
    int v = trie.node[u][i];
    if (v) {
      cur += dfs(trie, v, d + 1);
    }
  }
  ll t = cur / k;
  cur %= k;
  ans += t * d;
  return cur;
}

void solve() {
  cin >> n >> k;
  // if (n > 50) {
  //   assert(0);
  // }
  // assert(0);
  vector<string> a(n);
  int len = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    len += a[i].size();
  }
  xuyixuyi();
  Trie trie(len + 10);
  for (int i = 0; i < n; i++) {
    trie.add(a[i]);
  }
  xuyixuyi();
  ans = 0;
  dfs(trie, 0, 0);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
