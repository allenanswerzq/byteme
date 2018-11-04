#include<bits/stdc++.h>
using namespace std;


bool check(int aa) {
  int res = 1;
  while (res < aa) {
  res *= 2;
  }
  return res == aa;
}

class Solution {
public:
  bool reorderedPowerOf2(int aa) {
  vi bb;
  while (aa) {
    bb.pb(aa % 10); 
    aa /= 10;
  }  
  sort(all(bb));
  do {
    // pvi(bb);
    int x = 0;
    if (bb[0] == 0) continue; 
    fori (i, 0, sz(bb)) {
    x *= 10; 
    x += bb[i];
    }
    // trace(x);
    if (check(x)) return 1;
  } while (next_permutation(all(bb)));
  return 0;
  }
};

int main() {
 
  Solution go;
  cout << go.reorderedPowerOf2(1) << endl;
  cout << go.reorderedPowerOf2(10) << endl;
  cout << go.reorderedPowerOf2(16) << endl;
  cout << go.reorderedPowerOf2(24) << endl;
  cout << go.reorderedPowerOf2(64) << endl;
  return 0;
}
