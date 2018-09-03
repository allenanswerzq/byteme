#include<bits/stdc++.h>
using namespace std;


const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

vi check(vi& a, vi& b) {
  vi res;
  fori(i, 0, sz(b)) {
  if (a[i] > b[i]) return {};
  res.pb(b[i] - a[i]);
  }
  return res;
}

class Solution {
public:
  int shoppingOffers(vector<int>& aa, vector<vector<int>>& bb, 
       vector<int>& cc) {
  // The price if we dont use any special offer.
  int res = inner_product(all(aa), cc.begin(), 0);
  fora (b, bb) {
  // The rest of items we need to buy after we choose this offer.
  vi r = check(b, cc);
  if (sz(r)) {
  // If we choose this offer, the price we can get.
  res = min(res, b.bk() + shoppingOffers(aa, bb, r)); 
  } 
  }
  return res;
  }
};

void test(vi aa, vvi bb, vi cc) {
  Solution go;
  int r = go.shoppingOffers(aa, bb, cc);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  test({2, 5}, {{3, 0, 5}, {1, 2, 10}}, {3, 2});
  return 0;
}
