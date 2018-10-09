#include<bits/stdc++.h>
using namespace std;

// Very good solution 
// basic idea is that calculate occurrence of 1 on 
// every digit position, and then sum them up

// ref: https://leetcode.com/problems/number-of-digit-one/discuss/64382/JavaPython-one-pass-solution-easy-to-understand
// Let n = 4560000

// How many nums with "1" at the thousand's position?

// 4551000 to 4551999 (1000)
// 4541000 to 4541999 (1000)
// 4531000 to 4531999 (1000)
// ...
// 1000 to 1999 (1000)

// That's 456 * 1000

// What if n = 4561234?

// 4561000-4561234 (1234+1)
// 4551000 to 4551999 (1000)
// 4541000 to 4541999 (1000)
// 4531000 to 4531999 (1000)
// ...
// 1000 to 1999 (1000)

// That's 456 * 1000 + 1234 + 1

// What if n = 4562345?
// 4561000-4561999 (1000)
// 4551000 to 4551999 (1000)
// 4541000 to 4541999 (1000)
// 4531000 to 4531999 (1000)
// ...
// 1000 to 1999 (1000)

// That's 456*1000 + 1000

// Same for hundred's position.

// Let n = 4012

// How many nums with "1" at the hundred's position?

// 3100-3999 (100)
// 2100-2999 (100)
// 1100-1999 (100)
// 100 to 199 (100)
// That's 4 * 100

// Let n = 4111

// 4100-4111 ( 11 + 1)
// 3100-3999 (100)
// 2100-2999 (100)
// 1100-1999 (100)
// 100 to 199 (100)
// That's 4 * 100 + 11 + 1

// Let n = 4211

// 4100-4199 (100)
// 3100-3999 (100)
// 2100-2999 (100)
// 1100-1999 (100)
// 100 to 199 (100)
// That's 4 * 100 + 100

// Same for ten's digit

// Let n = 30
// How many nums with "1" at the ten's position?

// 210-219 (10)
// 110-119 (10)
// 10-19 (10)

// That's 3 * 10

// Let n = 312

// 310-312 (2 + 1)
// 210-219 (10)
// 110-119 (10)
// 10-19 (10)
// That's 3 * 10 + 2 + 1

// Let n = 322

// 310-319 (10)
// 210-219 (10)
// 110-119 (10)
// 10-19 (10)
// That's 3 * 10 + 10

// Same for one's digit

// Let n = 30
// How many nums with "1" at the one's position?

// 21 (1)
// 11 (1)
// 1(1)
// That's 3 * 1

// Let n = 31
// How many "1" are there at the one's position?
// 31 (1)
// 21 (1)
// 11 (1)
// 1 (1)
// That's 3 * 1 + 1

// Let n = 32
// How many "1" are there at the one's position?
// 31 (10)
// 21 (10)
// 11 (10)
// 1 (10)
// That's 3 * 1 + 1

// Let n = 3

// only 1 (10 of "1" at one's position)

// That's 0 * 1 + 1

class Solution {
public:
  int countDigitOne(int kk) {
    if (kk <= 0) return 0;
    int total = 0, layer = 1, pop = 0, curr = kk;
    
    while (curr > 0) {
      pop = curr % 10;
      curr /= 10;
      
      if (pop == 0)
        total += (curr * layer);
      else if (pop == 1)
        total += (curr * layer + (kk % layer + 1));
      else
        total += ((curr + 1) * layer); 

      layer *= 10;
    }
    return total;
  }
};

int main(int argc, char** argv) {
  return 0;
}
