#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
class Solution {
public:
  int maxProduct(vector<int>& nums) {
  return res;
  }
};

void TEST(vi aa) {
  Solution go;
  cout << go.maxProduct(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 

  TEST({2,3,-2,4});
  TEST({-2,0,-1});

  return 0;
}
