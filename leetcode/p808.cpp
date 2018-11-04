#include<bits/stdc++.h>
using namespace std;


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

int main() {
   test(50);
  return 0;
}
