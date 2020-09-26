/* created   : 2020-09-26 14:45:14
 * accepted  : 2020-09-26 14:53:45
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int canCompleteCircuit(vector<int>& G, vector<int>& C) {
    int n = G.size();
    for (int i = 0; i < n; i++) {
      G.push_back(G[i]);
      C.push_back(C[i]);
    }
    vector<int> f(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
      f[i + 1] = f[i] + G[i] - C[i];
    }
    // trace(G);
    // trace(C);
    // trace(f);
    auto get = [&](int x, int y) { return f[y + 1] - f[x]; };
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j = 0; j < n; j++) {
        // 4 -3 2 -3 3 -4
        // 4  1 3 0  3 -1
        // trace(i, i + j, get(i, i + j));
        if (get(i, i + j) < 0) {
          ok = false;
          break;
        }
      }
      if (ok) return i;
    }
    return -1;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<int> G, vector<int> C) {
  Solution sol;
  return sol.canCompleteCircuit(G, C);
}

void solve() {
  EXPECT(test({2, 3, 4}, {3, 4, 3}), -1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
