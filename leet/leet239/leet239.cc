/* created   : 2020-10-04 22:24:41
 * accepted  : 2020-10-04 23:35:55
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  vector<int> maxSlidingWindowSet(vector<int>& A, int K) {
    multiset<int> st;
    vector<int> ans;
    int n = A.size();
    for (int j = 0, i = 0; i < n; i++) {
      while (j < n && j - i < K) {
        st.insert(A[j++]);
      }
      // cout << i << " " << j << "\n";
      if (j - i == K) {
        ans.push_back(*st.rbegin());
      }
      st.erase(st.find(A[i]));
    }
    return ans;
  }

  vector<int> maxSlidingWindow(vector<int>& A, int K) {
    deque<int> qu;
    int n = A.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      while (qu.size() && i - qu.front() >= K) {
        // (j....i]
        //   ---K--
        qu.pop_front();
      }
      while (qu.size() && A[i] >= A[qu.back()]) {
        qu.pop_back();
      }
      qu.push_back(i);
      if (i >= K - 1) {
        ans.push_back(A[qu.front()]);
      }
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

vector<int> test(vector<int> A, int K) {
  Solution sol;
  auto ans = sol.maxSlidingWindow(A, K);
  trace(ans);
  return ans;
}

void solve() {
  EXPECT(test({1, 3, -1, -3, 5, 3, 6, 7}, 3), vector<int>({3, 3, 5, 5, 6, 7}));
  EXPECT(test({1, -1}, 1), vector<int>({1, -1}));
  EXPECT(test({7, 2, 4}, 2), vector<int>({7, 4}));
  EXPECT(test({1, 3, 1, 2, 0, 5}, 3), vector<int>({3, 3, 2, 5}));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
