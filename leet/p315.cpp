#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
class Solution {
public:
  vector<int> countSmaller(vector<int>& aa) {
    vi res, bb;
    n = sz(aa);
    bb = aa;
    if (n <= 0) return res;
    bit.resize(n + 1);
    res.resize(n);
    unordered_map<int, int> mp;

    sort(all(bb));
    fori (i, 0, n) 
      mp[bb[i]] = i; 

    ford (i, n-1, -1) {
      res[i] = query(mp[aa[i]] - 1);
      update(mp[aa[i]], 1);
      pvi(bit);
    }
    return res;
  }

  void update(int ix, int inp) {
    ix += 1;
    while (ix <= n) {
      bit[ix] += inp;
      ix += ix & (-ix);
    } 
  }

  int query(int ix) {
    int res = 0;
    ix += 1;
    while (ix > 0) {
      res += bit[ix];
      ix -= ix & (-ix);
    }
    return res;
  }

  vi bit;
  int n;
};

void test(vi aa) {
  Solution go;
  vi res = go.countSmaller(aa);
  pvi(res);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  // test({-1, -1});
  test({5, 2, 6, 1});
  // test({7, 2, 8, 6, 5, 1});
  return 0;
}
