#include<bits/stdc++.h>
using namespace std;




const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

unordered_map<int, unordered_map<int, double>> mp;

double go(int aa, int bb) {
  if (aa == 0 && bb)
    return 1;
  else if (aa == 0 && bb == 0)
    return 0.5;
  else if (aa && bb == 0)
    return 0;

  if (mp[aa][bb])
    return mp[aa][bb];

  double res = 0;
  res += 0.25 * go(aa - min(aa, 100), bb);
  res += 0.25 * go(aa - min(aa, 75), bb - min(bb, 25));
  res += 0.25 * go(aa - min(aa, 50), bb - min(bb, 50));
  res += 0.25 * go(aa - min(aa, 25), bb - min(bb, 75)); 

  mp[aa][bb] = res;
  return res;
}


class Solution {
public:
  double soupServings(int n) {
    if (n > 50000) return 1;
    return go(n, n);
  }
};

void test(int n) {
  Solution go;
  double r = go.soupServings(n);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  test(50);
  return 0;
}
