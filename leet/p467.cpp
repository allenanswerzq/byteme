#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int findSubstringInWraproundString(string aa) {
  int res, cnt;
  vi dp(26, 0);
  dp[aa[0] - 'a'] = 1;
  res = 0;
  cnt = 1;
  fori (i, 1, sz(aa)) {
    int a, b;
    a = aa[i] - 'a';
    b = aa[i-1] - 'a';
    if (a - b == 1 || a - b == -25)
    ++cnt;
    else cnt = 1;
    dp[a] = max(dp[a], cnt);
  }
  return accumulate(all(dp), 0);
  }
};

void test(str aa) {
  Solution go;
  int r = go.findSubstringInWraproundString(aa);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test("ba");
  test("zab");
  test("cac");
  str aa = "cdefghefghijklmnopqrstuvwxmnijklmnopqrstuvbcdefghijklmnopqrstuvwabcddefghijklfghijklmabcdefghijklmnopqrstuvwxymnopqrstuvwxyz";
  test(aa);
  return 0;
}
