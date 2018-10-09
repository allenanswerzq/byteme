#include<bits/stdc++.h>
using namespace std;

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

int main(int argc, char** argv) {
  return 0;
}
