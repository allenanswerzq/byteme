#include<bits/stdc++.h>
using namespace std;


const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

vector<int> a;
int dfs(int bit, int sum) {
  if (bit == 0) return 1;
  for (int i=(1<<a.size())-1; i>=0; i--) {
  i &= bit;

  int tot = 0;
  for (int j=0; j<a.size(); j++)
    if (i & (1<<j))
    tot += a[j];

  if (tot == sum) {
    int tmp = dfs(bit ^ i, sum);
    if (tmp) return 1;
  }
  }
  return 0;
}

class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int i,sum;
    sum = 0;
    for (i=0; i<nums.size(); i++)
    sum += nums[i];
    if (sum % k != 0) return false;
    sum /= k;
    a = nums;
    return dfs((1<<a.size()) - 1, sum);
  }
};

void test() {
  Solution go;
  int r;
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
