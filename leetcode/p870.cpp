#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> advantageCount(vector<int>& aa, vector<int>& bb) {
    int n = sz(aa);
    vpii ap(n), bp(n);
    fori (i, 0, n) {
      ap[i] = {aa[i], i};
      bp[i] = {bb[i], i};
    }

    sort(all(ap));
    sort(all(bp));

    vi ans(n, -1);
    vi st;
    int i, j;

    i = j = 0;
    while (i < n && j< n) {
      if (ap[i].fi > bp[j].fi) {
        ans[bp[j].se] = ap[i].fi;
        ++i; ++j;
      } else {
        st.pb(ap[i].fi);
        ++i;
      }
    }

    fori (i, 0, n)
      if (ans[i] == -1) {
        ans[i] = st.back();
        st.ppb();
      }
    return ans;
  }
};

int main() {
  return 0;
}
