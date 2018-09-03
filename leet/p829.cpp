#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int consecutiveNumbersSum(int N) {
  if (N == 1) return 1;
  int n = sqrt(2 * N) + 1;     
  int res = 0;
  fori(i, 1, n+1) {
  int t = N - i * (i-1) / 2;
  if (t && i<N && t % i == 0) {
  ++res;
  }
  }
  return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
