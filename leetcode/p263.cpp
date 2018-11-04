#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isUgly(int num) {
    if (num == 0) return false;
    if (num == 1) return true;
    vector<int> primes = {2, 3, 5};
    for (int i = 0; i < 3; ++i) {
      if (num % primes[i] == 0)
        if (isUgly(num / primes[i])) 
          return true;
    }
    return false;
  }
};

class Solution {
public:
  bool isUgly(int num) {
    if (num <= 0) return 0;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
  }
};

int main() {
  return 0;
}
