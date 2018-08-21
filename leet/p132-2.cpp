#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool check(string s) {
  int n = sz(s);
  int lo, hi;
  lo = 0, hi = n-1;
  while(lo < hi) 
    if (s[lo++] != s[hi--])
      return false;
  return true;
}

int recu(string s, int lo, int hi) {
  if (lo >= hi) return 0;
  if (check(s.substr(lo, hi-lo+1)))
    return 0;
  else {
    int mi = 0x3f3f3f3f;
    fori(k, lo, hi) {
      mi = min(mi, recu(s, lo, k) + 1 + recu(s, k+1, hi)); 
    }
    return mi;
  }
  return -1;
}

class Solution {
public:
  int minCutRecu(string s) {
    return recu(s, 0, sz(s)-1);
  }
  
  // TODO
  int minCutDP(string s) {
    return 0;
  }

  int minCut(string s) {
    srand(time(0));
    int x = rand();
    // if (x % 2)
    return minCutRecu(s); 
    // else
      // return minCutDP(s);
  }
};

void TEST(string s) {
  Solution go;
  cout << go.minCut(s) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 


  // TEST("abcd");
  TEST("aab");
  // TEST("ababbbabbababa");

  return 0;
}
