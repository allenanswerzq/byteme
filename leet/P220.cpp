#include<bits/stdc++.h>

// |nums[i] - x | <= t
// -t <= num[i]-x <= t
// x <= num[i] + t and x >= num[i] - t

#define ll long long

// TODO
bool containsNearbyAlmostDuplicate(vector<int>& aa, int k, int t) {
  set<ll> st;
  for (int i=0; i<aa.size(); ++i) {
  if (i > k) st.erase(aa[i - k - 1]);
  auto pos = st.lower_bound((ll)aa[i] - t);     
  if (pos != st.end() && *pos <= (ll)(aa[i]) + t)
  return true;
  st.insert(aa[i]);
  }
  return false;
}
