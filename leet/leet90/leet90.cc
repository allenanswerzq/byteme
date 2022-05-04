/* created   : 2020-09-19 21:59:39
 * accepted  : 2020-09-19 22:41:45
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  vector<vector<int>> ans;
  void dfs(const vector<int>& A, vector<int>& path, int u) {
    ans.push_back(path);
    for (int i = u; i < A.size(); i++) {
      if (i > u && A[i] == A[i - 1]) continue;
      path.push_back(A[i]);
      dfs(A, path, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDupDfs(vector<int>& A) {
    sort(A.begin(), A.end());
    vector<int> path;
    dfs(A, path, 0);
    return ans;
  }

  vector<vector<int>> subsetsWithDup(vector<int>& A) {
    if (A.empty()) return ans;
    sort(A.begin(), A.end());
    int last = A[0];
    int start = 0;
    ans.push_back({});
    for (int i = 0; i < A.size(); i++) {
      if (A[i] != last) {
        last = A[i], start = 0;
      }
      int cnt = ans.size();
      for (int j = start; j < cnt; j++) {
        ans.push_back(ans[j]);
        ans.back().push_back(A[i]);
      }
      start = cnt;
    }
    return ans;
  }

  vector<vector<int>> subsetsWithDup(vector<int>& A) {
    sort(A.begin(), A.end());
    int n = A.size();
    vector<vector<int>> ans;
    // 1, 2, 2, 2
    for (int i = 0; i < (1 << n); i++) {
      vector<int> cur;
      bool ok = true;
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) {
          if (j && A[j-1] == A[j] && !(i >> (j - 1) & 1)) {
            ok = false;
            break;
          }
          else {
            cur.push_back(A[j]);
          }
        }
      }
      if (ok) ans.push_back(cur);
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void test(vector<int> a) {
  Solution sol;
  trace(sol.subsetsWithDup(a));
}

void solve() {
  test({1, 2, 2});
  test({4, 4, 4, 1, 4});
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
