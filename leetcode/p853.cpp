#include<bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  int carFleet(int target, vector<int>& aa, vector<int>& bb) {
  vector<pii> a;
  int n = sz(aa);
  if (n == 1) return 1;

  fori(i, 0, n)  {
    a.eb(aa[i], bb[i]); 
  } 
  sort(all(a));

  // fori(i, 0, n) {
  //   cout << "{ " << a[i].fi << " " << a[i].se << " } ";
  // } 
  // cout << "\n";

  int res = 0;
  ford(i, n-1, -1) {
  }
  return res;
  }
};

int main() {
   // vi aa = {2, 4};
  // vi bb = {3, 2};
  // Solution go;
  // cout << go.carFleet(10, aa, bb) << "\n"; 
  vi aa = {10,8,0,5,3};
  vi bb = {2,4,1,1,3};
  Solution go;
  cout << go.carFleet(12, aa, bb) << "\n"; 
  return 0;
}
