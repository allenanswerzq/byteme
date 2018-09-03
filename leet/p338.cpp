#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:

  int count(int inp) {
  int cnt = 0;
  while (inp) {
  inp = inp & (inp - 1);
  ++cnt;
  }  
  return cnt;
  }

  vector<int> countBits(int aa) {
  vi res;
  fori(i, 0, aa+1) {
  res.pb(count(i));
  } 
  return res;
  }
};

void TEST(int inp) {
  Solution go;
  pvi(go.countBits(inp));
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 

  TEST(5);
  
  return 0;
}
