#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
class RangeModule {
public:
  RangeModule() {
  lo = inf;
  hi = -inf; 
  }
  
  void addRange(int left, int right) {
  lo = min(left, lo);     
  hi = max(right, hi);
  }
  
  bool queryRange(int left, int right) {
  if (left >= lo && right < hi)
    return 1;
  else 
    return 0;    
  }
  
  void removeRange(int left, int right) {
  lo = max(lo, left);
  hi = min(hi, right); 
  }

  int lo;
  int hi;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

void test() {
  Solution go;
  int r;
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
