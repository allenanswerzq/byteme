/* created   : 2022-05-01 16:03:09
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  vector<int> right_most(vector<int> &v) {
    // right most index that greater or equal than current
    vector<int> ans(v.size());
    set<array<int, 2>> st;
    for (int i = (int)v.size() - 1; i >= 0; i--) {
      if (st.empty() || v[i] > (*st.rbegin())[0]) {
        st.insert({v[i], i});
      }
      auto it = st.lower_bound({v[i], -1});
      ans[i] = (*it)[1];
    }
    return ans;
  }

  vector<int> left_most(vector<int> &v) {
    // left most index that greater or equal than current
    vector<int> ans(v.size());
    set<array<int, 2>> st;
    for (int i = 0; i < (int)v.size(); i++) {
      if (st.empty() || v[i] > (*st.rbegin())[0]) {
        st.insert({v[i], i});
      }
      auto it = st.lower_bound({v[i], -1});
      ans[i] = (*it)[1];
    }
    return ans;
  }

  int maxArea(vector<int> &H) {
    vector<int> L = left_most(H);
    vector<int> R = right_most(H);
    int ans = 0;
    for (int i = 0; i < H.size(); i++) {
      ans = max(ans, H[i] * (R[i] - L[i]));
    }
    return ans;
  }
};
