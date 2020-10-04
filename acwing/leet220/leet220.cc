/* created   : 2020-10-04 09:14:21
 * accepted  : 2020-10-04 09:40:29
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& A, int K, int T) {
    multiset<ll> st;
    for (int j = 0, i = 0; i < A.size(); i++) {
      while (j < A.size() && j - i <= K) {
        auto pt = st.lower_bound((ll) A[j] - T);
        auto it = st.upper_bound((ll) A[j] + T);
        // [pt...it)
        if (it != pt) return true;
        st.insert(A[j]);
        j++;
      }
      st.erase(st.find(A[i]));
    }
    return false;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

bool test(vector<int> A, int K, int T) {
  Solution sol;
  return sol.containsNearbyAlmostDuplicate(A, K, T);
}

void solve() {
  EXPECT_TRUE(test({1, 2, 3, 1}, 3, 0));
  EXPECT_TRUE(test({1, 0, 1, 1}, 1, 2));
  EXPECT_FALSE(test({1, 5, 9, 1, 5, 9}, 2, 3));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
