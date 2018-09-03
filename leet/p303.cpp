#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
  NumArray(vector<int> aa) {
  int n = sz(aa);
  dp.resize(n+1);
  dp.clear();
  dp[0] = 0;
  fori(i, 1, n+1) {
  dp[i] = dp[i-1] + aa[i-1]; 
  } 
  }
  
  int sumRange(int i, int j) {
  return dp[j+1] - dp[i]; 
  }

private:
  int n;
  // dp[i] denotes the sum range of [0...i-1].
  vi dp; 
};

void test(vi aa) {
  NumArray go(aa);
  cout << go.sumRange(0, 2) << "\n";
  cout << go.sumRange(2, 5) << "\n";
  cout << go.sumRange(0, 5) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({-2, 0, 3, -5, 2, -1});
  return 0;
}
