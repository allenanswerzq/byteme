/* created   : 2020-09-21 23:46:16
 * accepted  : 2020-09-22 23:06:47
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ull unsigned long long

class Solution {
public:
  int ladderLength(string B, string E, vector<string>& W) {
    int n = W.size();
    int start = -1;
    int end = -1;
    for (int i = 0; i < n; i++) {
      if (W[i] == B) start = i;
      if (W[i] == E) end = i;
    }
    if (end == -1) return 0;
    if (start == -1) {
      W.push_back(B);
      start = n++;
    }
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      mp[W[i]] = i;
    }
    vector<vector<int>> g(n);
    for (auto & w : W) {
      int u = mp[w];
      for (int j = 0; j < w.size(); j++) {
        char b = w[j];
        for (char c = 'a'; c <= 'z'; c++) {
          w[j] = c;
          if (mp.count(w)) {
            int v = mp[w];
            if (u == v) continue;
            g[u].push_back(v);
          }
        }
        w[j] = b;
      }
    }
    // cout << start << " " << end << endl;
    // auto check = [&](int i, int j) {
    //   if (W[i].size() != W[j].size()) return false;
    //   int c = 0;
    //   for (int k = 0; k < W[i].size(); k++) {
    //     c += W[i][k] != W[j][k];
    //   }
    //   return c == 1;
    // };
    // vector<vector<int>> g(n + 1);
    // for (int i = 0; i < n; i++) {
    //   for (int j = i + 1; j < n; j++) {
    //     if (check(i, j)) {
    //       g[i].push_back(j);
    //       g[j].push_back(i);
    //     }
    //   }
    // }
    const int INF = 1e9 + 7;
    vector<int> dist(n, INF);
    vector<int> vis(n);
    dist[start] = 1;
    vis[start] = 1;
    vector<int> qu;
    qu.push_back(start);
    for (int i = 0; i < qu.size(); i++) {
      int u = qu[i];
      for (int v : g[u]) {
        if (vis[v]) continue;
        dist[v] = min(dist[v], dist[u] + 1);
        qu.push_back(v);
        vis[v] = 1;
      }
    }
    return dist[end] == INF ? 0 : dist[end];
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(const string& B, const string& E, vector<string> W) {
  Solution sol;
  return sol.ladderLength(B, E, W);
}

void solve() {
  EXPECT(test("hit", "cog",
              vector<string>({"hot", "dot", "dog", "lot", "log", "cog"})),
         5);

  EXPECT(
      test("hit", "cog", vector<string>({"hot", "dot", "dog", "lot", "log"})),
      0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
