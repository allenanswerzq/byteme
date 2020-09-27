/* created   : 2020-09-27 23:22:10
 * accepted  : 2020-09-27 23:53:47
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

namespace std {
template <>
struct hash<vector<int>> {
  size_t operator()(const vector<int>& v) const {
    size_t seed = v.size();
    for (auto x : v) {
      seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};
}

class Solution {
 public:
  int maxPoints(vector<vector<int>>& A) {
    if (A.size() == 0) return 0;
    if (A.size() == 1) return 1;
    unordered_map<vector<int>, set<vector<int>>> cxx;
    unordered_map<vector<int>, int> cnt;
    for (auto& a : A) {
      cnt[{a[0], a[1]}]++;
    }
    int n = A.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (A[i][0] == A[j][0]) {
          cxx[{A[i][0], 0, 0, 0}].insert({A[i][0], A[i][1]});
          cxx[{A[i][0], 0, 0, 0}].insert({A[j][0], A[j][1]});
        }
        else if (A[i][1] == A[j][1]) {
          cxx[{0, A[i][1], 0, 0}].insert({A[i][0], A[i][1]});
          cxx[{0, A[i][1], 0, 0}].insert({A[j][0], A[j][1]});
        }
        else if (A[i][0] == A[j][0] && A[i][1] == A[j][1]) {
          // assert(false);
        }
        else {
          int dy = A[i][1] - A[j][1];
          int dx = A[i][0] - A[j][0];
          int g = __gcd(dy, dx);
          int t = (dx * 1ll * A[i][1] - dy * 1ll * A[i][0]);
          int f = __gcd(t, dx);
          // dx * y = dy x + b * dx
          // b = (dx * y - dy * x) / dx
          cxx[{dx / g, dy / g, t / f, dx / f}].insert({A[i][0], A[i][1]});
          cxx[{dx / g, dy / g, t / f, dx / f}].insert({A[j][0], A[j][1]});
        }
      }
    }
    int ans = 0;
    for (auto& it : cxx) {
      int sum = 0;
      for (auto& t : it.second) {
        sum += cnt[t];
      }
      trace(sum, it);
      ans = max(ans, sum);
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<vector<int>> A) {
  Solution sol;
  return sol.maxPoints(A);
}

void solve() {
  EXPECT(test({{1,1},{1,1},{0,0},{3,4},{4,5},{5,6},{7,8},{8,9}}), 5);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
