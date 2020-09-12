/* created   : 2020-09-12 09:47:39
 * accepted  : 2020-09-12 16:32:10
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int jump(vector<int>& A) {
    return jumpBest(A);
    // return jumpNaive(A);
  }

  int jumpBest(vector<int>& A) {
    int n = A.size();
    int reach = 0; // how far i can reach at this place
    int last = 0;
    int step = 0;
    for (int i = 0; i < n; i++) {
      reach = min(max(reach, i + A[i]), n - 1);
      if (i == last) {
        last = reach;
        step++;
      }
    }
    return step - 1;
  }

  int jumpNaive(vector<int>& A) {
    if (A.empty()) return 0;
    int n = A.size();
    const int INF = 1e9;
    vector<int> f(n, INF);
    f[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
      int step = A[i];
      for (int k = 0; k <= step && i + k < n; k++) {
        f[i] = min(f[i], f[i + k] + 1);
      }
    }
    return f[0];
  }
};

int test(vector<int> a) {
  Solution sol;
  return sol.jump(a);
}

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {
  EXPECT(test({2, 3, 1, 1, 4}), 2);
  EXPECT(test({2, 1}), 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
