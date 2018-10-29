#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class Solution {
public:
  int maxProduct(vector<int>& aa) {
    int n = aa.size();
    int ret, mi, mx;
    ret = mx = mi = aa[0];
    for (int i = 1; i < n; ++i) {
      int a = mx * aa[i], b = mi * aa[i];
      mx = max(max(a, b), aa[i]);
      mi = min(min(a, b), aa[i]);
      ret = max(mx, ret);
      // cout << mi << " " << mx << " " << ret << '\n';
    }
    return ret;
  }
};

void test(vi aa) {
  Solution go;
  auto r = go.maxProduct(aa);
  cout << r << '\n';
}

int main(int argc, char** argv) {
  test({1, 3, 0, -1, -8});
  return 0;
}
