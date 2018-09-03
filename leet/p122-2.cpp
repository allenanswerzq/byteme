#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int maxProfit(vector<int>& aa) {
  int n = sz(aa);
  int res = 0;
  for(int i=0; i<n; ) {
  int k = i;
  while (k+1<n && aa[k]<=aa[k+1]) ++k;
  res += aa[k] - aa[i];
  i = k+1;
  }  
  return res;
  }

  int maxProfit(vi& aa) {
  int n = sz(aa);
  int res = 0;
  fori (i, 0, n - 1) {
  if (aa[i+1] > aa[i])
  res += aa[i+1] - aa[i];
  }
  return res;
  }
};

void TEST(vi aa) {
  Solution go;
  cout << go.maxProfit(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  
  TEST({7,1,5,3,6,4});
  TEST({1,2,3,4,5});
  TEST({7,6,4,3,1});

  return 0;
}
