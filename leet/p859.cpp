#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  bool buddyStrings(string A, string B) {
    int a, b;
    a = sz(A), b = sz(B);
    if (a != b) return false;
    vector<pii> two;
    fori(i, 0, a) {
      if (A[i] != B[i])
        two.eb(A[i], B[i]);
    }

    int n = sz(two);
    if (n == 0) {
      // Note: declare and reset a array.
      int cnt[26] = {};
      fori(i, 0, a) {
        cnt[A[i] - 'a']++;
        if (cnt[A[i] - 'a'] > 1) return true;
      } 
      return false;
    }
    if (n != 2) return 0;
    return two[0].fi == two[1].se && two[0].se == two[1].fi;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
