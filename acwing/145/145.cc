/* created   : 2020-06-08 05:45:09
 * accepted  : 2020-06-08 06:51:07
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
  // vector<int> leaf;
  int p = 1;

  Trie() {
    node.resize(N);
    // leaf.resize(N);
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
    // leaf[u]++;
  }

  ll find(const string& s) {
    int u = 0;
    ll ret = 0;
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

string get(int a) {
  string x;
  for (int j = 0; j < 31; j++) {
    x += (a >> (30 - j) & 1) + '0';
  }
  return x;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  const int N = 3e6 + 7;
  Trie<N> trie;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    trace(i, a[i], get(a[i]));
    trie.add(get(a[i]));
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, trie.find(get(a[i])));
  }
  cout << ans << "\n";
  // while (1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
