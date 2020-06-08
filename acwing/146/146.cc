/* created   : 2020-06-08 18:33:42
 * accepted  : 2020-06-08 21:51:15
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

template <int N>
struct Trie {
  vector<array<int, 2>> node;
  int p = 1;

  Trie() {
    node.resize(N);
  }

  int get(char ch) { return ch - '0'; }

  void add(const string& s) {
    int u = 0;
    for (auto ch : s) {
      int v = get(ch);
      assert(u < N);
      if (!node[u][v]) {
        node[u][v] = p++;
      }
      u = node[u][v];
    }
  }

  int find(const string& s) {
    int u = 0;
    int ret = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      int v = get(s[i]);
      assert(u < N);
      if (node[u][1 - v]) {
        u = node[u][1 - v];
        ret |= (1 << (30 - i));
      }
      else if (node[u][v]) {
        u = node[u][v];
      }
      else {
        assert(false);
        return ret;
      }
    }
    return ret;
  }
};

const int N = 1e5 + 7;
vector<pair<int, int>> g[N];
bool use[N];
int val[N];

void dfs(int u) {
  use[u] = true;
  for (auto e : g[u]) {
    int v = e.x, w = e.y;
    if (!use[v]) {
      val[v] = val[u] ^ w;
      dfs(v);
    }
  }
}

string get(int a) {
  string x;
  for (int j = 0; j < 31; j++) {
    x += (a >> (30 - j) & 1) + '0';
  }
  return x;
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(0);
  trace(mt(val, n));
  Trie<31 * N> trie;
  for (int i = 0; i < n; i++) {
    trie.add(get(val[i]));
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, trie.find(get(val[i])));
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
