#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Bit manipulation
  // Assume the finally result are a,b
  vector<int> singleNumber(vector<int>& aa) {
    int diff = 0;
    int a = 0, b = 0;

    for (auto n : aa) diff ^= n; // after this pass, diff = a^b
    // Because a and b are distinct, so at least one bit is different
    // We can use this to split a and b into two different groups
    // We dont care other numbers located in which group because the quantity of those number are even
    // After xor operation, that will be equal to zero
    diff = diff & ~(diff-1); 
    // Differences between x and x-1 in binary form is that there will have a rightmost one bit divide this number into two parts  
    // Left part is the same, and the right part is oppsite. for example right and ~right
    // So if we not(~) diff-1, the bits of left part will be changed to the opposite side of diff
    // And if we and(&) them, the result will be zero. on the other side, the right part will become the same as diff
    // And after and(&) operator, we will get the rightmost bit
    for (auto n : aa) {
      if (n & diff) a ^= n;
      else b ^= n;
    } 
    return {a, b};
  }
};

int main(int argc, char** argv) {
  return 0;
}