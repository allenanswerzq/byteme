#include<bits/stdc++.h>
using namespace std;

// naive way tle
int rangeBitwiseAnd(int m, int n) {
  int res = -1;
  for (int i=m; i<=n; ++i)
    res &= i;
  return res;
}

// Find the same left most part.
class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
  int i = 0;
  while (m != n) {
    m >>= 1;
    n >>= 1;
    ++i;
  }
  return (m << i);
  }
};

int rangeBitwiseAnd(int m, int n) {
  return n>m ? (rangeBitwiseAnd(m>>1, n>>1) << 1) : m;
}

int main(int argc, char** argv) {
  return 0;
}
