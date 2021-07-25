/* created   : 2020-09-12 17:50:21
 * accepted  : 2020-09-13 08:54:44
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  bool canReachBfs(vector<int>& A, int P) {
    int n = A.size();
    deque<int> qu;
    qu.push_back(P);
    vector<bool> seen(n);
    seen[P] = true;
    while (qu.size()) {
      int t = qu.front(); qu.pop_front();
      if (A[t] == 0) return true;
      int lo = t - A[t];
      if (lo >= 0 && lo != t && !seen[lo]) {
        seen[lo] = true;
        qu.push_back(lo);
      }
      int hi = t + A[t];
      if (hi < A.size() && hi != t && hi != lo && !seen[hi]) {
        seen[hi] = true;
        qu.push_back(hi);
      }
    }
    return false;
  }

  bool dfs(vector<vector<int>>& g, vector<bool>& seen, vector<int>& A, int u) {
    trace(u, A[u]);
    seen[u] = true;
    if (A[u] == 0) return true;
    for (int v : g[u]) {
      if (!seen[v]) {
        if (dfs(g, seen, A, v)) return true;
      }
    }
    return false;
  }

  bool canReachDfs(vector<int>& A, int P) {
    int n = A.size();
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
      int x = i - A[i];
      int y = i + A[i];
      if (x >= 0 && x != i) {
        g[i].push_back(x);
        g[x].push_back(i);
      }
      if (y < n && y != i && x != y) {
        g[y].push_back(i);
        g[i].push_back(y);
      }
    }
    vector<bool> seen(n);
    if (dfs(g, seen, A, P)) return true;
    return false;
  }

  bool canReach(vector<int>& A, int P) {
    return canReachBfs(A, P);
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

bool test(vector<int> a, int p) {
  Solution sol;
  return sol.canReach(a, p);
}

void solve() {
  int N, P; cin >> N >> P;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  cout << test(A, P) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
