#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

// bit manipulation
// Assume the finally result are a,b
vector<int> singleNumber(vector<int>& nums) {
  int diff = 0;
  int a=0, b=0;

  for (auto n : nums) diff ^= n; // after this pass, diff = a^b
  // Because a and b are distinct, so at least one bit is different
  // We can use this to split a and b into two different groups
  // We dont care other numbers located in which group because the quantity of those number are even
  // After xor operation, that will be equal to zero
  diff &= ~(diff-1); 
  // Differences between x and x-1 in binary form is that there will have a rightmost one bit divide this number into two parts  
  // Left part is the same, and the right part is oppsite. for example right and ~right
  // So if we not(~) diff-1, the bits of left part will be changed to the opposite side of diff
  // And if we and(&) them, the result will be zero. on the other side, the right part will become the same as diff
  // And after and(&) operator, we will get the rightmost bit
  for (auto n : nums) {
    if (n & diff) a ^= n;
    else b ^= n;
  } 
  return {a, b};
}