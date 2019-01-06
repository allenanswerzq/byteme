#include <bits/stdc++.h>
using namespace std;

bool check(string ss) {
  int lo, hi;
  lo = 0, hi = sz(ss) - 1;
  while (lo < hi) 
    if (ss[lo++] != ss[hi--])
      return false;
  return true;
}

int recu(string ss, int lo, int hi) {
  if (lo >= hi) return 0;
  if (check(ss.substr(lo, hi - lo + 1)))
    return 0;
  else {
    int mi = 0x3f3f3f3f;
    fori (k, lo, hi) {
      mi = min(mi, recu(ss, lo, k) + 1 + recu(ss, k + 1, hi)); 
    }
    return mi;
  }
  return -1;
}

class Solution {
public:
  int minCutRecu(string ss) {
    return recu(ss, 0, sz(ss) - 1);
  }
  
  // TODO
  int minCutDP(string ss) {
    return 0;
  }

  int minCut(string ss) {
    srand(time(0));
    int x = rand();
    if (x % 2) return minCutRecu(ss); 
    else return minCutDP(ss);
  }
};

void test(string ss) {
  Solution go;
  cout << go.minCut(ss) << "\n";
}

int main() {
 
  test("abcd");
  test("aab");
  test("ababbbabbababa");

  return 0;
}
