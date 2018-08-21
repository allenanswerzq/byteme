#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
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
