#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isPrime(int x) {
    int ones = 0;
    while (x) {
      ones++;
      x = x & (x - 1);
    }
    for (int i = 2; i*i <= ones; ++i){
      if (ones % i == 0) return 0;
    }
    return 1;
  }

  int countPrimeSetBits(int L, int R) {
    int ret=0;
    for (int i=L; i<R; ++i) {
      if (isPrime(i))
        ret++;
    }
    return ret;
  }
};

