#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  typedef long long int64;
  int trailingZeroes(int n) {
    return n == 0 ? 0: n / 5 + trailingZeroes(n / 5);
  }
};

int main() {
  return 0;
}
