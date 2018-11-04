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
  while (i<n && j<n) {
    if (ap[i].fi > bp[j].fi) {
    ans[bp[j].se] = ap[i].fi;   
    ++i;
    ++j;
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
 
  Solution go;
  // vi aa = {2, 7, 11, 15};
  // vi bb = {1, 10, 4, 11};
  // vi aa = {0};
  // vi bb = {0};
  vi aa = {15,15,4,5,0,1,7,10,3,1,10,10,8,2,3};
  vi bb = {4,13,14,0,14,14,12,3,15,12,2,0,6,9,0};
  vi r = go.advantageCount(aa, bb);
  pvi(r);
  return 0;
}
