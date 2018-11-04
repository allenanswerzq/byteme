#include<bits/stdc++.h>
using namespace std;
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
  int shoppingOffers(vi& aa, vvi& bb, vi& cc) {
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
  output(r);
}

int main() {
  test({2, 5}, {{3, 0, 5}, {1, 2, 10}}, {3, 2});
  return 0;
}
