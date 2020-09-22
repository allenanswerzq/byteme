/* created   : 2020-09-21 23:46:16
 * accepted  : 2020-09-22 23:06:47
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ull unsigned long long

struct HashString {
  static const int base = 131;

  static ull get(const string& s) {
    ull ans = 1;
    for (char c : s) {
      ans = ans * base + c - 'a';
    }
    return ans;
  }
};

class Solution {
 public:
  int ladderLength(const string& B, const string& E, vector<string>& W) {
    W.push_back(B);
    int n = W.size();
    auto check = [](const string& a, const string& b) {
      int cnt = 0;
      for (int k = 0; k < a.size(); k++) {
        cnt += (a[k] != b[k]);
        if (cnt > 1) return false;
      }
      return cnt == 1;
    };
    vector<vector<int>> g(n);
    int dst = -1;
    for (int i = 0; i < n; i++) {
      if (W[i] == E) {
        dst = i;
      }
      for (int j = i + 1; j < n; j++) {
        if (check(W[i], W[j])) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }
    if (dst == -1) {
      return 0;
    }
    vector<ull> word(n);
    for (int i = 0; i < n; i++) {
      word[i] = HashString::get(W[i]);
    }
    ull val = HashString::get(E);
    int src = n - 1;
    deque<int> qu;
    vector<bool> use(n);
    qu.push_back(src);
    use[src] = true;
    int level = 0;
    while (qu.size()) {
      int m = qu.size();
      level++;
      for (int i = 0; i < m; i++) {
        int u = qu.front();
        qu.pop_front();
        if (word[u] == val) return level;
        for (int v : g[u]) {
          if (!use[v]) {
            use[v] = true;
            qu.push_back(v);
          }
        }
      }
    }
    return 0;
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
